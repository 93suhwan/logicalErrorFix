#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int n, m, a[100005], dfn[100005], f[18][100005], T, dfr[100005], d[100005];
long long t[100005];
void dfs(int p, int fa) {
  f[0][p] = fa;
  dfn[p] = ++T;
  d[p] = d[fa] + 1;
  for (int i = 1; i < 18; ++i) f[i][p] = f[i - 1][f[i - 1][p]];
  for (int x : v[p])
    if (x != fa) dfs(x, p);
  dfr[p] = T + 1;
}
void add(int p, int v) {
  for (; p < 100005; p += p & -p) t[p] += v;
}
long long ask(int p, long long a = 0) {
  for (; p; p -= p & -p) a += t[p];
  return a;
}
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 17; ~i; --i)
    if (d[x] - d[y] >> i & 1) x = f[i][x];
  if (x == y) return x;
  for (int i = 17; ~i; --i)
    if (f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
  return f[0][x];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] = abs(a[i]);
  for (int i = 1, a, b; i < n; ++i)
    scanf("%d%d", &a, &b), v[a].push_back(b), v[b].push_back(a);
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) add(dfn[i], a[i]), add(dfr[i], -a[i]);
  for (int i = 1; i <= m; ++i) {
    int o, x, y;
    scanf("%d%d%d", &o, &x, &y);
    y = abs(y);
    if (o == 1)
      add(dfn[x], y - a[x]), add(dfr[x], a[x] - y), a[x] = y;
    else
      printf("%lld\n", (ask(dfn[x]) + ask(dfn[y]) - ask(dfn[lca(x, y)]) -
                        ask(dfn[f[0][lca(x, y)]])) *
                               2 -
                           a[x] - a[y]);
  }
}
