#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryIndexedTree {
 private:
  vector<T> c;

 public:
  void Build(int n) { c = vector<T>(n + 1, 0); }
  void Add(int x, T v) {
    for (; x < c.size(); x += x & -x) c[x] += v;
  }
  T Sum(int x) {
    T ret = 0;
    for (; x; x -= x & -x) ret += c[x];
    return ret;
  }
};
void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n + 1);
  vector<vector<int>> G(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int N = 0;
  while (1 << (N + 1) < n) N++;
  int dfs_clock = 0;
  vector<int> dep(n + 1), pre(n + 1), post(n + 1);
  vector<vector<int>> fa(n + 1, vector<int>(N + 1));
  function<void(int)> dfs = [&](int u) {
    for (int i = 1; i <= N; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    pre[u] = ++dfs_clock;
    for (int v : G[u]) {
      if (v == fa[u][0]) continue;
      fa[v][0] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
    post[u] = dfs_clock;
  };
  dep[1] = 1;
  dfs(1);
  auto get_lca = [&](int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = N; i >= 0; i--)
      if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    for (int i = N; i >= 0; i--)
      if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    if (u != v) u = fa[u][0];
    return u;
  };
  BinaryIndexedTree<long long> bit;
  bit.Build(n);
  auto modify = [&](int u, int c) {
    c = abs(c);
    bit.Add(pre[u], c - a[u]);
    bit.Add(post[u] + 1, a[u] - c);
    a[u] = c;
  };
  auto query = [&](int u, int v) {
    if (u == v) return 0LL;
    int lca = get_lca(u, v);
    long long ans = 0;
    ans += bit.Sum(pre[u]) + bit.Sum(pre[v]);
    ans -= 2 * bit.Sum(pre[lca]);
    ans += a[lca];
    ans *= 2;
    ans -= a[u] + a[v];
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    int w = a[i];
    a[i] = 0;
    modify(i, w);
  }
  for (int i = 0; i < q; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
      modify(x, y);
    else
      cout << query(x, y) << '\n';
  }
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
