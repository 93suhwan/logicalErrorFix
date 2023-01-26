#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, k, mod, tot;
int f[maxn][maxn][maxn], g[maxn][maxn], c[maxn][maxn];
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &mod);
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) f[i][0][0] = 1LL * f[i - 1][0][0] * i % mod;
  for (int j = 1; j <= m; j++) f[0][j][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int u = 1; u <= i; u++)
        g[i][j] = max(g[i][j], g[u - 1][j - 1] + g[i - u][j - 1] + (j == 1));
      for (int p = 0; p <= g[i][j]; p++) {
        int np = p - (j == 1);
        if (np < 0) continue;
        for (int u = 1; u <= i; u++)
          for (int v = max(0, np - g[i - u][j - 1]); v <= g[u - 1][j - 1]; v++)
            f[i][j][p] = (f[i][j][p] + 1LL * f[u - 1][j - 1][v] *
                                           f[i - u][j - 1][np - v] % mod *
                                           c[i - 1][u - 1]) %
                         mod;
      }
    }
  printf("%d\n", f[n][m][k]);
  return 0;
}
