#include <bits/stdc++.h>
const int M = 15;
const int MOD = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, ans, a[M], b[1 << M], zs[M][1 << M], dp[1 << M], cnt[1 << M];
long long qkpow(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}
signed main() {
  n = read();
  for (long long i = 0; i < n; i++) a[i] = read(), b[1 << i] = a[i];
  for (long long i = 0; i < n; i++) {
    zs[i][0] = 1;
    for (long long j = 1; j < (1 << n); j++) {
      long long x = j & (-j);
      zs[i][j] = zs[i][j ^ x] * a[i] % MOD * qkpow(a[i] + b[x], MOD - 2) % MOD;
    }
  }
  for (long long s = 1; s < (1 << n); s++) {
    dp[s] = 1;
    cnt[s] = cnt[s >> 1] + (s & 1);
    for (long long i = (s - 1) & s; i; i = (i - 1) & s) {
      long long p = 1;
      for (long long j = 0; j < n; j++)
        if (i & (1 << j)) p = p * zs[j][s - i] % MOD;
      dp[s] -= dp[i] * p;
      dp[s] %= MOD;
    }
  }
  for (long long s = 1; s < (1 << n); s++) {
    long long p = 1;
    for (long long i = 0; i < n; i++)
      if (s & (1 << i)) p = p * zs[i][(1 << n) - 1 - s] % MOD;
    ans += dp[s] * cnt[s] % MOD * p;
    ans %= MOD;
  }
  printf("%lld\n", (ans + MOD) % MOD);
}
