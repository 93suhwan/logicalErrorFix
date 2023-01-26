#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n, m, q, fa[N], siz[N];
long long pre[N], ans[N], P[N], A = 0;
pair<int, int> f[N], g[N], k[N];
int find(int u) { return u == fa[u] ? fa[u] : fa[u] = find(fa[u]); }
void merge(int u) {
  A -= ans[u];
  A -= ans[find(u + 1)];
  siz[fa[u + 1]] += siz[u];
  ans[fa[u + 1]] = pre[fa[u + 1]] - pre[fa[u + 1] - siz[fa[u + 1]]];
  A += ans[fa[u + 1]];
  fa[u] = find(u + 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &f[i].first), f[i].second = 1;
  for (int i = 1; i <= m; i++)
    scanf("%d", &f[n + i].first), f[n + i].second = 2;
  sort(f + 1, f + n + m + 1);
  for (int i = 1; i < n + m; i++)
    g[i] = pair<int, int>(f[i + 1].first - f[i].first, i);
  sort(g + 1, g + n + m);
  for (int i = 1; i <= q; i++) scanf("%d", &k[i].first), k[i].second = i;
  sort(k + 1, k + q + 1);
  for (int i = 1; i <= n + m; i++) fa[i] = i, pre[i] = pre[i - 1] + f[i].first;
  for (int i = 1; i <= n + m; i++)
    if (f[i].second == 1) {
      siz[i] = 1;
      ans[i] = f[i].first;
      A += ans[i];
    }
  for (int i = 1, top = 1; i <= q; i++) {
    while (top < n + m && k[i].first >= g[top].first) {
      merge(g[top].second);
      top++;
    }
    P[k[i].second] = A;
  }
  for (int i = 1; i <= q; i++) printf("%lld\n", P[i]);
  return 0;
}
