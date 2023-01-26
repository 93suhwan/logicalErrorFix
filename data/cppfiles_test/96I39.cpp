#include <bits/stdc++.h>
using namespace std;
void in(long long &x) {
  x = 0;
  char c = getchar();
  long long y = 1;
  while (c < '0' || c > '9') {
    if (c == '-') y = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= y;
}
void o(long long x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) o(x / 10);
  putchar(x % 10 + '0');
}
const long long _ = 510;
const long long mod = 998244353;
long long ksm(long long x, long long p, long long res = 1) {
  for (; p; p >>= 1, x = x * x % mod)
    if (p & 1ll) res = res * x % mod;
  return res;
}
long long c[_][_];
long long dp[_][_];
signed main() {
  c[0][0] = 1;
  for (long long i = 1; i < _; i++) {
    c[i][0] = 1;
    for (long long j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  long long n, x;
  in(n);
  in(x);
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j <= x; j++) {
      if (j - i + 1 <= 0) dp[i][j] += ksm(j, i) - ksm(j - 1, i);
      dp[i][j] = (dp[i][j] + mod) % mod;
      for (long long ii = i; ii <= n; ii++) {
        dp[ii][j + ii - 1] +=
            dp[i][j] * c[ii][ii - i] % mod * ksm(ii - 1, ii - i) % mod;
        dp[ii][j + ii - 1] %= mod;
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= x; i++) ans += dp[n][i], ans %= mod;
  cout << ans;
  return 0;
}
