#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char* sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
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
void ps(int x) { cout << x << endl; }
void ps(ll x) { cout << x << endl; }
void ps(char x) { cout << x << endl; }
void ps(string x) { cout << x << endl; }
void ps(vector<ll> a) {
  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}
const int md = 1e9 + 7;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void setIO(string s) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int maxn = 1e6 + 10;
int n, m, nq, nk;
string str;
class DSU {
 public:
  vector<int> p;
  int n;
  DSU(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
void task() {
  cin >> n >> m >> nq;
  vi a(n), b(m);
  ll result = 0;
  for (int i = 0; i < n; ++i) cin >> a[i], result += a[i];
  for (int j = 0; j < m; ++j) cin >> b[j];
  vector<pair<int, int>> c;
  for (int i = 0; i < n; ++i) c.push_back(make_pair(a[i], 1));
  for (int i = 0; i < m; ++i) c.push_back(make_pair(b[i], 0));
  sort(c.begin(), c.end());
  multiset<pair<int, int>> tr;
  for (int i = 1; i < c.size(); ++i)
    tr.insert(make_pair(c[i].first - c[i - 1].first, i));
  DSU dsu(c.size());
  vector<pair<int, int>> q(nq);
  for (int i = 0; i < nq; ++i) {
    cin >> q[i].first;
    q[i].second = i;
  }
  vector<ll> pres(c.size() + 1), pres2(c.size() + 1), sz(c.size()),
      sz2(c.size());
  for (int i = 0; i < c.size(); ++i) {
    pres2[i + 1] = pres2[i];
    if (c[i].second) {
      sz2[i] = 1;
      pres2[i + 1] += c[i].first;
    }
    sz[i] = 1;
    pres[i + 1] = pres[i] + c[i].first;
  }
  sort(q.begin(), q.end());
  auto calc = [&](int R, int n1, int n2) {
    long long s = pres[R + 1] - pres[R + 1 - n2];
    long long s2 = pres2[R + 1] - pres2[R + 1 - n1];
    return s - s2;
  };
  vector<ll> ans(nq);
  for (int i = 0; i < nq; ++i) {
    int k = q[i].first;
    while (!tr.empty() && (*tr.begin()).first <= k) {
      int x = (*tr.begin()).second;
      int y = x - 1;
      int fx = dsu.get(x);
      int fy = dsu.get(y);
      if (fx != fy) {
        if (fx > fy) swap(fx, fy);
        dsu.p[fx] = fy;
        result -= calc(fx, sz[fx], sz2[fx]) + calc(fy, sz[fy], sz2[fy]);
        sz[fy] += sz[fx];
        sz2[fy] += sz2[fx];
        result += calc(fy, sz[fy], sz2[fy]);
      }
      tr.erase(tr.begin());
    }
    ans[q[i].second] = result;
  }
  for (int i = 0; i < nq; ++i) cout << ans[i] << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  int T = 1;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}
