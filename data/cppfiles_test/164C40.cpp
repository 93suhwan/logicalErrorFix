#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k, l[maxn], r[maxn];
char c[maxn];
vector<int> v;
void dfs(int u) {
  if (!u) return;
  dfs(l[u]);
  v.push_back(u);
  dfs(r[u]);
}
int f[maxn], g[maxn];
void calc(int u, int cst) {
  if (!u || cst > k) return;
  calc(l[u], cst + 1);
  if (g[l[u]])
    g[u] = 1;
  else if (f[u])
    g[u] = 1, k -= cst;
  if (g[u]) calc(r[u], 1);
}
int main() {
  scanf("%d%d%s", &n, &k, c + 1);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
  dfs(1);
  for (int i = n - 2; i >= 0; --i) {
    if (c[v[i]] < c[v[i + 1]])
      f[v[i]] = 1;
    else if (c[v[i]] == c[v[i + 1]])
      f[v[i]] = f[v[i + 1]];
  }
  calc(1, 1);
  for (int i = 0; i < n; ++i) {
    putchar(c[v[i]]);
    if (g[v[i]]) putchar(c[v[i]]);
  }
  return 0;
}
