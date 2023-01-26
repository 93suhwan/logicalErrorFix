#include <bits/stdc++.h>
using namespace std;
const long long N = 1000 + 5, Mod = 998244353;
long long n = 0, x = 0, ans = 0, dp[N][N] = {}, pw[N][N] = {}, C[N][N] = {};
int main() {
  scanf("%lld %lld", &n, &x);
  for (long long i = 0; i <= n; i++) {
    pw[i][0] = C[i][0] = 1;
    if (i > 0)
      for (long long j = 1; j <= n; j++)
        pw[i][j] = pw[i][j - 1] * i % Mod,
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
  }
  for (long long i = 2; i <= n; i++)
    for (long long j = 1; j <= min(i - 1, x); j++)
      dp[i][j] = (pw[j][i] - pw[j - 1][i] + Mod) % Mod;
  for (long long i = 2; i <= n; i++)
    for (long long j = 1; j <= x; j++)
      for (long long k = i; k <= n; k++)
        dp[k][j + k - 1] =
            (dp[k][j + k - 1] + dp[i][j] * pw[k - 1][k - i] % Mod * C[k][i]) %
            Mod;
  for (long long j = 1; j <= x; j++) ans = (ans + dp[n][j]) % Mod;
  printf("%lld", ans);
  return 0;
}
