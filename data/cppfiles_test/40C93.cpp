#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m, q, clk;
int deg[maxn], a[maxn], b[maxn];
int vis[maxn], in[maxn], out[maxn], par[maxn];
vector<int> g[maxn];
inline void dfs(int u, int p) {
  vis[u] = true;
  in[u] = ++clk, par[u] = p;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (vis[v]) continue;
    dfs(v, u);
  }
  out[u] = clk;
  return;
}
inline void solve(int u, int v) {
  vector<int> vec1, vec2;
  for (; !(in[u] <= in[v] && out[u] >= out[v]); u = par[u]) vec1.push_back(u);
  for (; v != u; v = par[v]) vec2.push_back(v);
  vec2.push_back(u);
  reverse(vec2.begin(), vec2.end());
  printf("%d\n", vec1.size() + vec2.size());
  for (int i = 0; i < vec1.size(); ++i) printf("%d ", vec1[i] + 1);
  for (int i = 0; i < vec2.size(); ++i) printf("%d ", vec2[i] + 1);
  puts("");
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(0, -1);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", a + i, b + i);
    ++deg[--a[i]], ++deg[--b[i]];
  }
  int delta = 0;
  for (int i = 0; i < n; ++i) delta += (deg[i] & 1);
  if (delta) {
    puts("NO");
    printf("%d\n", delta / 2);
    return 0;
  }
  puts("YES");
  for (int i = 0; i < q; ++i) solve(a[i], b[i]);
  return 0;
}
