#include <bits/stdc++.h>
using namespace std;
int n, k, l[200010], r[200010], pos[200010];
char c[200010];
vector<int> seq;
void precalc(int u) {
  if (l[u]) precalc(l[u]);
  seq.push_back(u);
  if (r[u]) precalc(r[u]);
}
bool good[200010], isDup[200010];
void dfs(int u, int cost) {
  if (!u || cost > k) return;
  dfs(l[u], cost + 1);
  if (isDup[l[u]])
    isDup[u] = 1;
  else if (good[u])
    isDup[u] = 1, k -= cost;
  if (isDup[u]) dfs(r[u], 1);
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  precalc(1);
  char lst = c[seq.back()];
  for (int i = n - 2; i >= 0; i--) {
    int u = seq[i], v = seq[i + 1];
    if (c[u] != c[v]) lst = c[v];
    if (c[u] < lst) good[u] = 1;
  }
  dfs(1, 1);
  for (auto u : seq) {
    putchar(c[u]);
    if (isDup[u]) putchar(c[u]);
  }
  return 0;
}
