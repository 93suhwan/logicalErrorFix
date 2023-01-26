#include <bits/stdc++.h>
using namespace std;
int T, n, m, K, pr[1010], a[1010], b[1010];
bool in[1010], fl;
vector<int> E[1010];
void doit(int u) {
  for (; u; u = pr[u]) in[u] = 1;
}
void dfs(int u, int fa, long long nw) {
  for (int v : E[u])
    if (v != fa && a[v] < nw && !(in[u] && in[v])) {
      if (in[v]) {
        fl = 1;
        return doit(u);
      }
      if (pr[v]) {
        fl = 1;
        return doit(v), doit(u);
      }
      pr[v] = u, dfs(v, u, nw + b[v]);
      if (fl) return;
    }
}
bool chk(int x) {
  for (int i = 1; i <= n; i++) in[i] = 0;
  in[1] = 1;
  while (1) {
    fl = 1;
    long long nw = x;
    for (int i = 1; i <= n; i++) pr[i] = 0, nw += b[i] * in[i], fl &= in[i];
    if (fl) return 1;
    fl = 0;
    for (int i = 1; i <= n && !fl; i++)
      if (in[i]) dfs(i, 0, nw);
    if (!fl) return 0;
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) E[i].resize(0);
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d%d", &u, &v), E[u].push_back(v), E[v].push_back(u);
  int l = 1, r = 1e9 + 2, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chk(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}
