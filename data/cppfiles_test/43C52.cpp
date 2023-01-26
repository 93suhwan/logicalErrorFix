#include <bits/stdc++.h>
using namespace std;
const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long sqr(long long x) { return x * x; }
long long sqr(int x) { return (long long)x * x; }
double sqr(double x) { return x * x; }
mt19937 mmtw(960172);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(mmtw) % (y - x + 1) + x;
}
template <typename T, typename M>
T& updMin(T& a, M const& b) {
  if (b < a) a = b;
  return a;
}
template <typename T, typename M>
T& updMax(T& a, M const& b) {
  if (a < b) a = b;
  return a;
}
long long divFloor(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? a / b : (a - b + 1) / b;
}
long long divCeil(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? (a + b - 1) / b : a / b;
}
long long divFloorS(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1;
}
long long divCeilS(long long a, long long b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1;
}
template <typename K, typename V>
V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) {
  auto it = a.find(k);
  return it == a.end() ? def : it->second;
}
template <typename K, typename V>
V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) {
  auto it = a.find(k);
  return it == a.end() ? def : it->second;
}
template <typename A, typename B>
istream& operator>>(istream& in, pair<A, B>& p) {
  return in >> p.first >> p.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& out, pair<A, B> const& p) {
  return out << p.first << " " << p.second;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (T& x : a) in >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}
template <typename T>
bool isZero(T const& x) {
  return x == T(0);
}
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template <typename T>
int sgn(T const& x) {
  if (isZero(x)) return 0;
  return x > 0 ? 1 : -1;
}
namespace tree {
const int N = 200511;
const int D = 18;
int n = 0;
vector<pair<int, int>> e[N];
int dep[N];
pair<int, int> tio[N];
int ct;
int pred[D][N];
int predMax[D][N];
void init(int nn) {
  for (int i = 0; i < n; ++i) e[i].clear();
  n = nn;
}
void dfs1(int v, int pv = -1, int px = -1, int cdep = 0) {
  tio[v].first = ct++;
  pred[0][v] = pv;
  predMax[0][v] = px;
  int cp = pv;
  for (int i = 1; i < D; ++i) {
    predMax[i][v] = max(predMax[i - 1][v], cp == -1 ? -1 : predMax[i - 1][cp]);
    pred[i][v] = cp = (cp == -1 ? -1 : pred[i - 1][cp]);
  }
  dep[v] = cdep;
  for (int i = 0; i < ((int)((e[v]).size())); ++i) {
    int nv = e[v][i].first;
    if (nv == pv) {
      e[v][i--] = e[v].back();
      e[v].pop_back();
      continue;
    }
    dfs1(nv, v, e[v][i].second, cdep + 1);
  }
  tio[v].second = ct;
}
void build(int root) {
  ct = 0;
  dfs1(root);
}
int up(int v, int c) {
  if (dep[v] < c || c < 0) return -1;
  for (int i = 0; c; ++i) {
    int m = 1 << i;
    if (c & m) {
      c ^= m;
      v = pred[i][v];
    }
  }
  return v;
}
int upMax(int v, int c) {
  int ans = -1;
  for (int i = 0; c && v != -1; ++i) {
    int m = 1 << i;
    if (c & m) {
      ans = max(ans, predMax[i][v]);
      c ^= m;
      v = pred[i][v];
    }
  }
  return ans;
}
bool isAnc(int x, int y) {
  return tio[x].first <= tio[y].first && tio[y].first < tio[x].second;
}
int lca(int x, int y) {
  if (isAnc(x, y)) return x;
  for (int i = D - 1; i >= 0; --i) {
    int nx = pred[i][x];
    if (nx != -1 && !isAnc(nx, y)) x = nx;
  }
  return pred[0][x];
}
int pathMax(int x, int y) {
  int z = lca(x, y);
  return max(upMax(x, dep[x] - dep[z]), upMax(y, dep[y] - dep[z]));
}
}  // namespace tree
struct DSU {
  vector<int> p;
  DSU() = default;
  explicit DSU(int n) : p(n, -1) {}
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, qn;
  cin >> n >> qn;
  tree::init(n);
  vector<int> es(n);
  cin >> es;
  struct Query {
    bool edge;
    int c;
    int x, y;
    int i;
  };
  vector<Query> qs;
  for (int i = 0; i < n - 1; ++i) {
    int x, y, c, t;
    cin >> x >> y >> c >> t;
    --x;
    --y;
    tree::e[x].push_back({y, t});
    tree::e[y].push_back({x, t});
    qs.push_back({true, c, x, y, -1});
  }
  tree::build(0);
  for (int i = 0; i < qn; ++i) {
    int v, x;
    cin >> v >> x;
    --x;
    qs.push_back({false, v, x, x, i});
  }
  sort((qs).begin(), (qs).end(), [](Query const& a, Query const& b) {
    if (a.c == b.c) return a.edge > b.edge;
    return a.c > b.c;
  });
  struct Comp {
    int maxE;
    int v;
    int maxCost;
  };
  vector<Comp> cs(n);
  for (int i = 0; i < n; ++i) {
    cs[i].maxE = es[i];
    cs[i].v = i;
    cs[i].maxCost = 0;
  }
  DSU dsu(n);
  vector<pair<int, int>> ans(qn);
  for (Query const& q : qs) {
    if (q.edge) {
      int x = dsu.get(q.x);
      int y = dsu.get(q.y);
      Comp& cx = cs[x];
      Comp& cy = cs[y];
      if (cx.maxE < cy.maxE)
        swap(cx, cy);
      else if (cx.maxE == cy.maxE) {
        cx.maxCost = max({cx.maxCost, cy.maxCost, tree::pathMax(cx.v, cy.v)});
      }
      dsu.merge(x, y);
    } else {
      Comp const& c = cs[dsu.get(q.x)];
      ans[q.i].first = c.maxE;
      ans[q.i].second = max(c.maxCost, tree::pathMax(q.x, c.v));
    }
  }
  for (pair<int, int> a : ans) cout << a << "\n";
  return 0;
}
