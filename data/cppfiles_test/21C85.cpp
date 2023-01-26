#include <bits/stdc++.h>
using namespace std;
const long long N = 102;
long long fac[N], C[N][N];
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m, k, mod;
  cin >> n >> m >> k >> mod;
  fac[0] = 1;
  for (long long i = 1; i < N; i++) fac[i] = i * fac[i - 1] % mod;
  C[0][0] = 1;
  for (long long i = 1; i < n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j < n; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  long long dp[n + 1][m + 1][n + 1];
  memset(dp, 0, sizeof dp);
  for (long long i = 0; i <= m; i++) {
    dp[0][i][0] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    dp[i][1][1] = fac[i];
  }
  for (long long i = 1; i < m; i++) {
    for (long long l = 0; l < n; l++) {
      for (long long p = 0; p <= l; p++) {
        if (!dp[l][i][p]) continue;
        for (long long r = 0; l + r < n; r++) {
          for (long long q = 0; q <= r; q++) {
            dp[l + r + 1][i + 1][p + q] +=
                dp[l][i][p] * dp[r][i][q] % mod * C[l + r][r] % mod;
            dp[l + r + 1][i + 1][p + q] %= mod;
          }
        }
      }
    }
  }
  cout << dp[n][m][k];
}
