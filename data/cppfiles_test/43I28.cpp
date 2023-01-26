#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N];
struct Edge {
  int u, v, w1, w2;
} e[N];
int f[N << 1];
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
int bz[N << 1][20], dp1[N << 1], dp2[N << 1];
void Kruskal() {
  sort(e + 1, e + n, [](const Edge &a, const Edge &b) { return a.w1 > b.w1; });
  for (int i = (1); i < (n * 2); ++i) f[i] = i;
  for (int i = (1); i <= (n); ++i) dp1[i] = a[i];
  for (int i = (1); i <= (n - 1); ++i) {
    int u = getf(e[i].u), v = getf(e[i].v);
    f[u] = f[v] = n + i;
    bz[u][0] = bz[v][0] = n + i;
    dp1[n + i] = max(dp1[u], dp1[v]);
    dp2[n + i] = max(e[i].w2, max(dp2[u], dp2[v]));
  }
  for (int i = (2 * n - 1); i >= (1); --i)
    for (int j = (1); j <= (18); ++j) bz[i][j] = bz[bz[i][j - 1]][j - 1];
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i)
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].w1, &e[i].w2);
  Kruskal();
  while (q--) {
    static int v, x;
    scanf("%d%d", &v, &x);
    for (int i = (18); i >= (0); --i)
      if (bz[x][i] && e[bz[x][i] - n].w1 >= v) x = bz[x][i];
    printf("%d %d\n", dp1[x], dp2[x]);
  }
  return 0;
}
