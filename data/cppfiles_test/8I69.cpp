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
  vector<long long> a(n);
  vector<vector<int>> G(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<int> son(n), dep(n), max_dep(n), fa(n);
  function<void(int)> dfs1 = [&](int u) {
    son[u] = -1;
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
  fa[0] = -1;
  dep[0] = 0;
  dfs1(0);
  int dfs_clock = 0;
  vector<int> pre(n), top(n);
  function<void(int u)> dfs2 = [&](int u) {
    pre[u] = ++dfs_clock;
    if (son[u] != -1) {
      top[son[u]] = top[u];
      dfs2(son[u]);
    }
    for (int v : G[u]) {
      if (v == fa[u] || v == son[u]) continue;
      top[v] = v;
      dfs2(v);
    }
  };
  top[0] = 0;
  dfs2(0);
  auto cost_f = [&](int u, int v) {
    if (v == -1) return 0LL;
    return max(abs(a[u] + a[v]), abs(a[u] - a[v]));
  };
  tree.Init(n);
  for (int i = 0; i < n; i++) tree.Update(pre[i], cost_f(i, son[i]));
  for (int i = 0; i < q; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      x--;
      long long dt = cost_f(x, son[x]);
      a[x] = y;
      dt = cost_f(x, son[x]) - dt;
      tree.Update(pre[x], dt);
    } else {
      x--, y--;
      long long ans = 0;
      while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += tree.Query(pre[top[x]], pre[x] - 1);
        ans += cost_f(fa[top[x]], top[x]);
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
