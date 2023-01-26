#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long p;
long long f[105][105][105];
long long C[105][105], inv[105];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> p;
  C[0][0] = 1 % p;
  for (int i = 1; i <= 100; i++)
    for (int j = 0; j <= i; j++) {
      C[i][j] += C[i - 1][j];
      if (j) C[i][j] += C[i - 1][j - 1];
      C[i][j] %= p;
    }
  inv[0] = 1 % p;
  int d;
  for (int i = 1; i <= 100; i++) inv[i] = inv[i - 1] * i % p;
  for (int i = 0; i <= m; i++) f[0][0][i] = 1 % p;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int l = 0; l <= m; l++) {
      if (l > i || l == 0) {
        f[0][i][l] = inv[i];
        continue;
      }
      d = 0;
      if (l == 1) d = 1;
      for (int j = 0; j <= min(i, k); j++) {
        for (int x = 0; x <= j - d; x++)
          for (int mx = x + 1; mx <= i - j + x + d; mx++) {
            if (f[x][mx - 1][l - 1] == 0 || f[j - x - d][i - mx][l - 1] == 0)
              continue;
            ans++;
            f[j][i][l] += f[x][mx - 1][l - 1] * f[j - x - d][i - mx][l - 1] %
                          p * C[i - 1][mx - 1] % p;
          }
        f[j][i][l] %= p;
      }
    }
  cout << f[k][n][m] << endl;
  return 0;
}
