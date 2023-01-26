#include <bits/stdc++.h>
using namespace std;
int n, m, kk, mod;
int jc[150];
int c[150][150];
int f[110][110][110];
signed main() {
  cin >> n >> m >> kk >> mod;
  jc[0] = 1;
  for (int i = 1; i <= n; i++) {
    jc[i] = jc[i - 1] * i;
    jc[i] %= mod;
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      c[i][j] %= mod;
    }
  }
  for (int i = 0; i <= n; i++) {
    f[0][i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    f[i][1][1] = jc[i];
    for (int j = i + 1; j <= n; j++) f[i][j][0] = jc[i];
    for (int j = 2; j <= min(i, m); j++) {
      for (int k = 0; k <= min(i - j + 1, kk); k++) {
        f[i][j][k] += f[i - 1][j - 1][k - (j == 1)] << 1;
        f[i][j][k] %= mod;
        for (int w = 2; w <= i - 1; w++) {
          for (int t = 0; t <= k - (j == 1); t++) {
            if (f[w - 1][j - 1][t] && f[i - w][j - 1][k - (j == 1) - t])
              f[i][j][k] += (((long long)f[w - 1][j - 1][t] *
                              f[i - w][j - 1][k - (j == 1) - t]) %
                             mod) *
                            c[i - 1][w - 1];
            f[i][j][k] %= mod;
          }
        }
      }
    }
  }
  cout << f[n][m][kk];
  return 0;
}
