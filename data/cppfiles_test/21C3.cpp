#include <bits/stdc++.h>
inline long long read() {
  long long num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline long long re1d() {
  char c = getchar();
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline long long min(long long a, long long b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
long long dp[105][105][105], C[105][105], fac[105];
long long n = read(), m = read(), k = read(), mod = read();
long long solve(long long c, long long d, long long x) {
  if (dp[c][d][x] != -1) return dp[c][d][x];
  if (c == 0) return x == 0 ? 1 : 0;
  if (d == 1) return x == 1 ? fac[c] : 0;
  if (x && x + x - 1 > c) return 0;
  dp[c][d][x] = 0;
  for (long long L = 0; L < c; L++)
    for (long long k = 0; k <= x; k++)
      dp[c][d][x] =
          (dp[c][d][x] + solve(L, d - 1, k) * solve(c - L - 1, d - 1, x - k) %
                             mod * C[c - 1][L]) %
          mod;
  return dp[c][d][x];
}
signed main() {
  memset(dp, -1, sizeof(dp));
  fac[0] = 1;
  for (long long i = 1; i <= (n); i++) {
    C[i][0] = C[i][i] = 1;
  }
  C[0][0] = 1;
  for (long long i = 1; i <= (n); i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (long long i = 1; i <= (n); i++) {
    for (long long j = 1; j <= (i - 1); j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  printf("%lld\n", solve(n, m, k));
  return 0;
}
