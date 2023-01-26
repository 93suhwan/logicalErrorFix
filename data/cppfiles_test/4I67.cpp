#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
namespace TCD {
int k;
vector<int> a;
vector<int> rem;
vector<int> size;
void dfs(const vector<vector<pair<int, int>>>& adj, int u, int p) {
  size[u] = 1;
  for (auto [v, t] : adj[u]) {
    if (v != p && !rem[v]) {
      dfs(adj, v, u);
      size[u] += size[v];
    }
  }
}
int findcentroid(const vector<vector<pair<int, int>>>& adj, int u) {
  int p = -1;
  dfs(adj, u, -1);
  int cap = size[u] >> 1;
  while (1) {
    int found = 0;
    for (auto [v, t] : adj[u]) {
      if (v != p && !rem[v] && cap < size[v]) {
        p = u, u = v;
        found = 1;
        break;
      }
    }
    if (!found) return u;
  }
  assert(0);
}
void workspace(const vector<vector<pair<int, int>>>&, int);
int res;
vector<vector<int>> fen(2);
vector<vector<int>> fen2(2);
void divide(const vector<vector<pair<int, int>>>& adj, int u = 0,
            int depth = 0) {
  if (!depth) {
    rem.resize(adj.size());
    fill(rem.begin(), rem.end(), 0);
    size.resize(adj.size());
    fen[0].resize(adj.size() + 1);
    fen[1].resize(adj.size() + 1);
    fen2[0].resize(adj.size() + 1);
    fen2[1].resize(adj.size() + 1);
  }
  u = findcentroid(adj, u);
  rem[u] = 1, workspace(adj, u);
  for (auto [v, t] : adj[u]) {
    if (!rem[v]) {
      divide(adj, v, depth + 1);
    }
  }
}
void workspace(const vector<vector<pair<int, int>>>& adj, int rt) {
  auto upd = [&](vector<int>& fen, int p, int v) {
    p++;
    for (; p < int((fen).size()); p += p & -p) {
      addmod(fen[p], v);
    }
  };
  auto query = [&](vector<int>& fen, int p) {
    p++;
    int res = 0;
    for (; 0 < p; p -= p & -p) {
      addmod(res, fen[p]);
    }
    return res;
  };
  int c;
  function<void(int, int, int, int, int, int)> dfs1 =
      [&](int u, int p, int d, int pt, int sum, int s) {
        addmod(sum, a[u]);
        upd(fen[c], d, mult(s, sum));
        upd(fen2[c], d, mult(s, 1));
        for (auto [v, t] : adj[u]) {
          if (v != p && !rem[v]) {
            int nd = d;
            if (t != pt) {
              nd++;
            }
            dfs1(v, u, nd, t, sum, s);
          }
        }
      };
  function<void(int, int, int, int, int)> dfs2 = [&](int u, int p, int d,
                                                     int pt, int sum) {
    addmod(sum, a[u]);
    addmod(res, mult(sum, query(fen2[c], k - d)));
    addmod(res, mult(sum, query(fen2[c ^ 1], k - d - 1)));
    addmod(res, query(fen[c], k - d));
    addmod(res, query(fen[c ^ 1], k - d - 1));
    if (d <= k) {
      addmod(res, sum);
    }
    for (auto [v, t] : adj[u]) {
      if (v != p && !rem[v]) {
        int nd = d;
        if (t != pt) {
          nd++;
        }
        dfs2(v, u, nd, t, sum);
      }
    }
  };
  for (auto [u, t] : adj[rt]) {
    if (!rem[u]) {
      c = t;
      dfs2(u, rt, 0, t, a[rt]);
      dfs1(u, rt, 0, t, 0, 1);
    }
  }
  for (auto [u, t] : adj[rt]) {
    if (!rem[u]) {
      c = t;
      dfs1(u, rt, 0, t, 0, -1);
    }
  }
  addmod(res, a[rt]);
}
}  // namespace TCD
void chemthan() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  vector<vector<pair<int, int>>> adj(n);
  for (int i = (0); i < (n - 1); ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    u--, v--;
    adj[u].push_back({v, t});
    adj[v].push_back({u, t});
  }
  TCD::k = k;
  TCD::a = a;
  TCD::divide(adj);
  cout << TCD::res << "\n";
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
