#include <bits/stdc++.h>
using namespace std;
int MOD;
int n, m, l;
int f[110][110][110], c[110][110], g[110];
int main() {
  cin >> n >> m >> l >> MOD;
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
  g[0] = 1;
  for (int d = 1; d <= n; d++) f[0][d][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++)
      g[i] = (g[i] + 1ll * g[j] * g[i - j - 1] % MOD * c[i - 1][j]) % MOD;
    f[i][1][1] = g[i];
    for (int j = 0; j < i; j++)
      for (int d = 1; d <= n; d++)
        for (int aj = 0; aj <= j; aj++)
          if (f[j][d][aj])
            for (int ak = 0; ak < i - j; ak++)
              f[i][d + 1][aj + ak] = (f[i][d + 1][aj + ak] +
                                      1ll * f[j][d][aj] * f[i - j - 1][d][ak] %
                                          MOD * c[i - 1][j]) %
                                     MOD;
  }
  cout << f[n][m][l];
}
