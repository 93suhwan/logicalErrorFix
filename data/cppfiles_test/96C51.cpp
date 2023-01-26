#include <bits/stdc++.h>
using namespace std;
long long dp[505][505];
long long pw[505][505];
long long c[505][505];
long long fast(long long x, long long y, long long k) {
  long long s = 1;
  while (y) {
    if (y % 2) s = s * x % k;
    x = x * x % k;
    y = y >> 1;
  }
  return s;
}
long long inv(long long x) { return fast(x, 998244353 - 2, 998244353); }
int32_t main() {
  c[0][0] = 1;
  for (long long i = 1; i <= 500; i++) {
    pw[i][0] = 1;
    for (long long j = 1; j <= 500; j++) {
      pw[i][j] = pw[i][j - 1] * i % 998244353;
    }
    c[i][0] = 1;
    for (long long j = 1; j <= 500; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 998244353;
    }
  }
  long long n, x;
  scanf("%lld%lld", &n, &x);
  for (long long i = 0; i <= x; i++) {
    dp[0][i] = 1;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= x; j++) {
      for (long long k = 0; k <= i; k++) {
        dp[i][j] += dp[i - k][max(0ll, j - (i - 1))] * pw[min(j, i - 1)][k] %
                    998244353 * c[i][k] % 998244353;
        dp[i][j] %= 998244353;
      }
    }
  }
  printf("%lld\n", dp[n][x]);
  return 0;
}
