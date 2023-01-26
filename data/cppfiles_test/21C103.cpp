#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mod;
long long dp[101][101][101];
long long fac[101];
long long bin[101][101];
long long calc(long long l, long long c, long long t) {
  if (dp[l][c][t] != -1) return dp[l][c][t];
  dp[l][c][t] = 0;
  if (t > 0 && (m < c || (m - c <= 20 && (1 << (m - c)) < t))) return 0;
  if (l == 0) {
    dp[l][c][t] = (t == 0);
  } else if (c > m) {
    if (t)
      dp[l][c][t] = 0;
    else
      dp[l][c][t] = fac[l];
  } else if (c == m) {
    if (t == 1)
      dp[l][c][t] = fac[l];
    else
      dp[l][c][t] = 0;
  } else {
    if (t > 0 && l - (m - c) < t) return 0;
    if ((l + 1) / 2 < t) return 0;
    for (long long l1 = 0; l1 < l; ++l1)
      for (long long t1 = 0; t1 <= t; ++t1) {
        long long l2 = l - l1 - 1, t2 = t - t1;
        dp[l][c][t] = (dp[l][c][t] + calc(l1, c + 1, t1) * calc(l2, c + 1, t2) %
                                         mod * bin[l - 1][l1]) %
                      mod;
      }
  }
  return dp[l][c][t];
}
int32_t main() {
  cin >> n >> m >> k >> mod;
  fac[0] = 1;
  for (long long i = 1; i <= 100; ++i) fac[i] = (fac[i - 1] * i) % mod;
  bin[0][0] = 1;
  for (long long n = 1; n <= 100; ++n)
    for (long long k = 0; k <= n; ++k)
      bin[n][k] = ((k ? bin[n - 1][k - 1] : 0) + bin[n - 1][k]) % mod;
  for (long long i = 0; i <= 100; ++i)
    for (long long j = 0; j <= 100; ++j)
      for (long long k = 0; k <= 100; ++k) dp[i][j][k] = -1;
  cout << calc(n, 1, k);
}
