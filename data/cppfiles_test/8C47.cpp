#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;
namespace KKT89 {
struct HLD {
  std::vector<std::vector<int>> g;
  std::vector<int> sz, in, out, head, par;
  HLD() {}
  HLD(std::vector<std::vector<int>> &_g)
      : g(_g),
        sz(_g.size()),
        in(_g.size()),
        out(_g.size()),
        head(_g.size()),
        par(_g.size()) {
    build();
  }
  void dfs_sz(int cur, int pre) {
    sz[cur] = 1;
    for (int &next : g[cur]) {
      if (next == pre) continue;
      dfs_sz(next, cur);
      par[next] = cur;
      sz[cur] += sz[next];
      if (sz[next] > sz[g[cur][0]]) std::swap(next, g[cur][0]);
    }
  }
  void dfs_hld(int cur, int pre, int &idx) {
    in[cur] = idx++;
    for (int &next : g[cur]) {
      if (next == pre) continue;
      if (next == g[cur][0])
        head[next] = head[cur];
      else
        head[next] = next;
      dfs_hld(next, cur, idx);
    }
    out[cur] = idx;
  }
  void build() {
    dfs_sz(0, -1);
    int idx = 0;
    dfs_hld(0, -1, idx);
  }
  void build(std::vector<std::vector<int>> &_g) {
    g = _g;
    sz.resize(g.size());
    in.resize(g.size());
    out.resize(g.size());
    head.resize(g.size());
    par.resize(g.size());
    dfs_sz(0, -1);
    int idx = 0;
    dfs_hld(0, -1, idx);
  }
  int lca(int u, int v) {
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
    }
  }
  std::vector<std::pair<int, int>> path_query(int u, int v, bool edge = false) {
    std::vector<std::pair<int, int>> ret;
    for (;; v = par[head[v]]) {
      if (in[u] > in[v]) std::swap(u, v);
      if (head[u] == head[v]) break;
      ret.emplace_back(in[head[v]], in[v] + 1);
    }
    ret.emplace_back(in[u] + edge, in[v] + 1);
    return ret;
  }
};
}  // namespace KKT89
namespace KKT89 {
template <typename T>
struct BinaryIndexedTree {
  int n;
  std::vector<T> bit;
  BinaryIndexedTree() : n(0) {}
  BinaryIndexedTree(int _n) : n(_n) { bit = std::vector<T>(n + 1); }
  void add1(int idx, T val) {
    for (int i = idx; i <= n; i += i & -i) bit[i] += val;
  }
  T sum1(int idx) {
    T res = 0;
    for (int i = idx; i > 0; i -= i & -i) res += bit[i];
    return res;
  }
  void add(int idx, T val) { add1(idx + 1, val); }
  T sum(int left, int right) { return sum1(right) - sum1(left); }
  int lower_bound(T x) {
    int res = 0;
    int k = 1;
    while (2 * k <= n) k <<= 1;
    for (; k > 0; k >>= 1) {
      if (res + k <= n and bit[res + k] < x) {
        x -= bit[res + k];
        res += k;
      }
    }
    return res;
  }
};
}  // namespace KKT89
void solve([[maybe_unused]] int CASE) {
  int n, kkt;
  cin >> n >> kkt;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  std::vector<std::vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int s, t;
    cin >> s >> t;
    s -= 1, t -= 1;
    g[s].emplace_back(t);
    g[t].emplace_back(s);
  }
  KKT89::HLD hld(g);
  KKT89::BinaryIndexedTree<ll> bit(n);
  auto update = [&](const int idx, const ll val) {
    const int in_idx = hld.in[idx];
    const ll cur = bit.sum(in_idx, in_idx + 1);
    bit.add(in_idx, val - cur);
  };
  for (int i = 0; i < n; ++i) {
    update(i, std::abs(a[i]));
  }
  while (kkt--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u;
      cin >> u;
      u -= 1;
      ll c;
      cin >> c;
      a[u] = c;
      update(u, std::abs(c));
    } else {
      int u, v;
      cin >> u >> v;
      u -= 1, v -= 1;
      if (u == v) {
        cout << 0 << "\n";
        continue;
      }
      ll res = 0;
      for (const auto &[l, r] : hld.path_query(u, v)) {
        res += bit.sum(l, r);
      }
      res *= 2;
      res -= std::abs(a[u]);
      res -= std::abs(a[v]);
      cout << res << "\n";
    }
  }
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int kkt = 1;
  for (int jupi = 1; jupi <= kkt; jupi++) solve(jupi);
  return 0;
}
