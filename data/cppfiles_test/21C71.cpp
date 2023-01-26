#include <bits/stdc++.h>
const int maxn = 105;
int n, m, k, mod;
int C[maxn][maxn], f[maxn][maxn][maxn];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &mod);
  for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 0; i <= m; i++) f[0][i][0] = 1;
  for (int i = 1; i <= n; i++)
    f[i][1][1] = i == 1 ? 1 : (1ll * f[i - 1][1][1] * i % mod);
  for (int i = 1; i < m; i++)
    for (int l = 0; l < n; l++)
      for (int p = 0; p <= l; p++)
        if (f[l][i][p])
          for (int r = 0; l + r < n; r++)
            for (int q = 0; q <= r; q++)
              if (f[r][i][q])
                f[l + r + 1][i + 1][p + q] =
                    (f[l + r + 1][i + 1][p + q] +
                     1ll * C[l + r][l] * f[l][i][p] % mod * f[r][i][q] % mod) %
                    mod;
  printf("%d\n", f[n][m][k]);
  return 0;
}
