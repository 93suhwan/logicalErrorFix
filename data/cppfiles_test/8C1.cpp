#include <bits/stdc++.h>
using namespace std;
const int N = 18;
struct zkw_segmentree {
  int M;
  long long sumv[2 << N];
  void Init(int n) {
    for (M = 1; M < n; M <<= 1)
      ;
    for (int i = 1; i < M << 1; i++) sumv[i] = 0;
  }
  void Update(int u, long long v) {
    for (u += M; u; u >>= 1) sumv[u] += v;
  }
  long long Query(int u, int v) {
    long long ret = 0;
    if (v < u) return ret;
    for (u += M - 1, v += M + 1; u ^ v ^ 1; u >>= 1, v >>= 1) {
      if (~u & 1) ret += sumv[u ^ 1];
      if (v & 1) ret += sumv[v ^ 1];
    }
    return ret;
  }
} tree;
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
  vector<int> son(n + 1), dep(n + 1), max_dep(n + 1), fa(n + 1);
  function<void(int)> dfs1 = [&](int u) {
    max_dep[u] = dep[u];
    for (int v : G[u]) {
      if (v == fa[u]) continue;
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfs1(v);
      if (max_dep[v] > max_dep[u]) {
        son[u] = v;
        max_dep[u] = max_dep[v];
      }
    }
  };
  dep[1] = 0;
  dfs1(1);
  int dfs_clock = 0;
  vector<int> pre(n + 1), top(n + 1);
  function<void(int u)> dfs2 = [&](int u) {
    pre[u] = ++dfs_clock;
    if (son[u]) {
      top[son[u]] = top[u];
      dfs2(son[u]);
    }
    for (int v : G[u]) {
      if (v == fa[u] || v == son[u]) continue;
      top[v] = v;
      dfs2(v);
    }
  };
  top[1] = 1;
  dfs2(1);
  auto cost_f = [&](int x, int y) { return max(abs(x + y), abs(x - y)); };
  tree.Init(n);
  for (int i = 1; i <= n; i++) {
    if (son[i]) {
      tree.Update(pre[i], cost_f(a[i], a[son[i]]));
    }
  }
  for (int i = 0; i < q; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      if (son[x]) {
        long long dt = cost_f(y, a[son[x]]) - cost_f(a[x], a[son[x]]);
        tree.Update(pre[x], dt);
      }
      if (top[x] != x) {
        long long dt = cost_f(y, a[fa[x]]) - cost_f(a[x], a[fa[x]]);
        tree.Update(pre[fa[x]], dt);
      }
      a[x] = y;
    } else {
      long long ans = 0;
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += tree.Query(pre[top[x]], pre[x] - 1);
        ans += cost_f(a[fa[top[x]]], a[top[x]]);
        x = fa[top[x]];
      }
      if (dep[x] > dep[y]) swap(x, y);
      ans += tree.Query(pre[x], pre[y] - 1);
      cout << ans << '\n';
    }
  }
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
