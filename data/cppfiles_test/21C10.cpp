#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const long long maxn = 105;
long long n, m, tk, p, dp[maxn][maxn][maxn], c[maxn][maxn], fac[maxn];
signed main() {
  n = read();
  m = read();
  tk = read();
  p = read();
  c[0][0] = 0;
  c[1][0] = c[1][1] = 1;
  fac[0] = 1;
  for (long long i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % p;
  for (long long i = 2; i < maxn; ++i) {
    for (long long j = 0; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      c[i][j] %= p;
    }
  }
  for (long long i = 0; i <= n; ++i) dp[0][i][0] = 1;
  for (long long i = 1; i <= n; ++i) {
    dp[i][1][1] = fac[i];
    for (long long j = i + 1; j <= n; ++j) dp[i][j][0] = fac[i];
    for (long long j = 2; j <= m && j <= i; ++j) {
      for (long long k = 0; k <= tk && k <= (i - j + 1); ++k) {
        dp[i][j][k] = (dp[i - 1][j - 1][k] * 2) % p;
        dp[i][j][k] %= p;
        for (long long l = 1; l < i - 1; ++l) {
          long long r = i - 1 - l;
          for (long long a = 0; a <= k; ++a) {
            long long b = k - a;
            if (dp[l][j - 1][a] == 0 || dp[r][j - 1][b] == 0) continue;
            long long temp =
                c[i - 1][l] * dp[l][j - 1][a] % p * dp[r][j - 1][b] % p;
            dp[i][j][k] += temp;
            dp[i][j][k] %= p;
          }
        }
      }
    }
  }
  cout << dp[n][m][tk];
  return 0;
}
