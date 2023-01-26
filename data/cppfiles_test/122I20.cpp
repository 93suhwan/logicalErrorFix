#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
void ps(T x) {
  cout << x << "\n";
}
template <class T>
void ps_vec(T a) {
  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << "\n";
}
const int md = 1e9 + 7;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
void setIO(string s) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int maxn = 1e6 + 10;
vi fa, g;
struct Edge {
  int x, y, z;
};
int find(int x) {
  if (x == fa[x])
    return x;
  else {
    int fx = fa[x];
    fa[x] = find(fa[x]);
    g[x] = g[x] ^ g[fx];
    return fa[x];
  }
}
void task() {
  int n, m;
  cin >> n >> m;
  fa = vi(n + 1);
  g = vi(n + 1);
  vector<Edge> edge;
  for (int i = 1; i <= n; ++i) fa[i] = i, g[i] = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    edge.push_back({x, y, z});
    if (z == -1) continue;
    int v = z & 1;
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
      fa[fx] = fy;
      g[fx] = g[x] ^ g[y] ^ v;
    }
  }
  42;
  bool ok = true;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    int fx = find(x);
    int fy = find(y);
    int v = z;
    if (fx != fy) {
      fa[fx] = fy;
      g[fx] = g[x] ^ g[y] ^ v;
      42;
    } else {
      if (g[x] ^ g[y] != v) {
        ok = false;
      }
    }
  }
  if (!ok) {
    ps("NO");
    return;
  }
  for (auto &e : edge) {
    int x = e.x, y = e.y;
    if (e.z != -1) continue;
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
      e.z = g[x] ^ g[y];
    } else {
      e.z = 0;
      fa[fx] = fy;
      g[fx] = g[x] ^ g[y];
    }
  }
  ps("YES");
  for (auto e : edge) {
    cout << e.x << " " << e.y << " " << e.z << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  int T = 1;
  cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}
