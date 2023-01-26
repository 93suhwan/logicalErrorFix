#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
const int N = 2e5 + 5, mod = 1e9 + 7;
template <int mod>
struct mod_int {
  int v;
  mod_int(long long _v = 0) : v(norm(_v)) {}
  inline int norm(long long a) { return a < 0 ? a % mod + mod : a % mod; }
  mod_int neg() const { return v == 0 ? 0 : mod - v; }
  template <typename T>
  explicit operator T() const {
    return v;
  }
  mod_int operator-() const { return neg(); }
  mod_int operator+() const { return mod_int(*this); }
  mod_int& operator--() {
    if (v == 0) v = mod;
    --v;
    return *this;
  }
  friend mod_int operator--(mod_int& a, int) {
    mod_int r = a;
    --a;
    return r;
  }
  mod_int& operator++() {
    ++v;
    if (v == mod) v = 0;
    return *this;
  }
  friend mod_int operator++(mod_int& a, int) {
    mod_int r = a;
    ++a;
    return r;
  }
  friend inline mod_int operator+(mod_int a, const mod_int& b) {
    return a += b;
  }
  mod_int& operator+=(const mod_int& oth) {
    if ((v += oth.v) >= mod) v -= mod;
    return *this;
  }
  friend inline mod_int operator-(mod_int a, const mod_int& b) {
    return a -= b;
  }
  mod_int& operator-=(const mod_int& oth) {
    if ((v -= oth.v) < 0) v += mod;
    return *this;
  }
  friend inline mod_int operator*(mod_int a, const mod_int& b) {
    return a *= b;
  }
  mod_int& operator*=(const mod_int& oth) {
    return *this = norm(1ll * v * oth.v);
  }
  mod_int pow(long long b) const {
    mod_int a = *this, r = 1;
    while (b) {
      if (b & 1) r *= a;
      b >>= 1;
      a *= a;
    }
    return r;
  }
  mod_int inv() const { return pow(mod - 2); }
  friend inline mod_int operator/(mod_int a, const mod_int& b) {
    return a /= b;
  }
  mod_int& operator/=(const mod_int& oth) { return *this *= oth.inv(); }
  friend std::ostream& operator<<(std::ostream& out, const mod_int& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& inp, mod_int& n) {
    long long x;
    inp >> x;
    n = mod_int(x);
    return inp;
  }
};
using Mint = mod_int<mod>;
struct edge {
  int v, w;
  edge(int _v, int _w) : v(_v), w(_w) {}
  bool operator<(const edge& o) const { return w < o.w; }
};
struct fenwick_tree {
  Mint bit[N];
  int ver[N], vercnt;
  inline void add(int x, Mint v) {
    for (++x; x < N; x += x & -x) {
      if (ver[x] ^ vercnt) ver[x] = vercnt, bit[x] = 0;
      bit[x] += v;
    }
  }
  inline Mint query(int x) {
    Mint r = 0;
    for (++x; x > 0; x -= x & -x) {
      if (ver[x] ^ vercnt) ver[x] = vercnt, bit[x] = 0;
      r += bit[x];
    }
    return r;
  }
  void clear() { ++vercnt; }
} sum, cnt;
vector<edge> adj[N];
bool mark[N];
int n, k, a[N], sz[N], tog[N];
int find_sz(int u, int p) {
  sz[u] = 1;
  for (auto [v, w] : adj[u])
    if (!mark[v] && v != p) sz[u] += find_sz(v, u);
  return sz[u];
}
int find_cen(int u, int p, const int& tot) {
  for (auto [v, w] : adj[u])
    if (!mark[v] && v != p)
      if (sz[v] > tot / 2) return find_cen(v, u, tot);
  return u;
}
Mint happy[N], res;
void pre_dfs(int u, int p, int c = -1) {
  if (tog[u] <= k) res += happy[u];
  for (auto [v, w] : adj[u])
    if (!mark[v] && v != p) {
      tog[v] = tog[u] + (c != -1 && c != w ? 1 : 0);
      happy[v] = happy[u] + a[v];
      pre_dfs(v, u, w);
    }
}
void dfs_add(int u, int p, const Mint& r) {
  cnt.add(tog[u], 1);
  sum.add(tog[u], happy[u] - r);
  for (auto [v, w] : adj[u])
    if (!mark[v] && v != p) dfs_add(v, u, r);
}
void dfs_query(int u, int p, int tg) {
  res += cnt.query(k - tg - tog[u]) * happy[u] + sum.query(k - tg - tog[u]);
  for (auto [v, w] : adj[u])
    if (!mark[v] && v != p) dfs_query(v, u, tg);
}
void centroid_decomp(int r) {
  int tot = find_sz(r, -1);
  r = find_cen(r, -1, tot);
  tog[r] = 0, happy[r] = a[r], pre_dfs(r, -1);
  for (auto [v, w] : adj[r])
    if (!mark[v]) {
      dfs_query(v, r, w);
      if (w == 0) dfs_add(v, r, happy[r]);
    }
  sum.clear(), cnt.clear();
  for (auto [v, w] : adj[r])
    if (!mark[v]) {
      if (w == 1) dfs_query(v, r, 0), dfs_add(v, r, happy[r]);
    }
  sum.clear(), cnt.clear();
  mark[r] = 1;
  for (auto [v, w] : adj[r])
    if (!mark[v]) centroid_decomp(v);
}
void Hollwo_Pelw() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1, u, v, w; i < n; i++)
    cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  centroid_decomp(1);
  cout << res << '\n';
}
