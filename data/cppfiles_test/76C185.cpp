#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x > y ? y : x; }
inline long long read() {
  long long a = 0;
  long long f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
inline void print(long long x) {
  if (!x) return;
  if (x) print(x / 10);
  putchar(x % 10 + '0');
}
long long T, n, dp[4000010], mod, sum[4000010];
signed main() {
  T = 1;
  while (T--) {
    n = read(), mod = read();
    dp[1] = 1, dp[2] = 2;
    sum[2] = 3;
    for (long long i = 3; i <= n; ++i) {
      for (long long l = 1, r; l <= i; l = r + 1) {
        r = i / (i / l);
        dp[i] += (r - l + 1) * dp[i / l] % mod;
        dp[i] %= mod;
      }
      dp[i] = (dp[i] + sum[i - 1]) % mod;
      sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}
