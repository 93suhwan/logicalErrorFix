#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int n, m, k, MOD;
inline void mod(int &x) {
  if (x >= MOD) x -= MOD;
}
int dp[102][102][102], C[102][102], fac[101];
int main() {
  cin >> n >> m >> k >> MOD;
  fac[0] = 1;
  for (int i = 1; i <= 100; i++) fac[i] = fac[i - 1] * 1LL * i % MOD;
  for (int i = 0; i <= 100; i++) C[i][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      mod(C[i][j]);
    }
  }
  for (int i = 0; i <= m; i++) dp[0][i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int m0 = 1; m0 <= i; m0++) {
        for (int s0 = 0; s0 <= j - 1; s0++) {
          for (int s1 = 0; s1 + s0 <= k && s1 <= i - j; s1++) {
            if (s0 + s1 + (m0 == 1) <= k) {
              dp[i][m0][s0 + s1 + (m0 == 1)] +=
                  (dp[j - 1][m0 - 1][s0] * 1LL * dp[i - j][m0 - 1][s1] % MOD) *
                  1LL * C[i - 1][j - 1] % MOD;
              mod(dp[i][m0][s0 + s1 + (m0 == 1)]);
            }
          }
        }
      }
    }
    dp[i][1][1] = i * 1LL * fac[i - 1] % MOD;
  }
  cout << dp[n][m][k];
}
