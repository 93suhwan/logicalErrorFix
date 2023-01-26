#include <bits/stdc++.h>
const int M = 1000005;
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
long long T, n, m, k, a, b, c, d, p, ans, s[M];
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
  T = read();
  while (T--) {
    memset(s, 0, sizeof s);
    n = read();
    m = read();
    a = read();
    b = read();
    c = read();
    d = read();
    p = read();
    p = p * qkpow(100, MOD - 2) % MOD;
    long long x = a, y = b, dx = 1, dy = 1;
    k = 0;
    while (1) {
      s[++k] = (a == c || b == d);
      if (a + dx > n || a + dx < 1) dx = -dx;
      if (b + dy > m || b + dy < 1) dy = -dy;
      a += dx;
      b += dy;
      if (a == x && b == y) break;
    }
    ans = 0;
    long long zxy = 1;
    for (long long i = 1; i <= k; i++) {
      ans = (ans + zxy) % MOD;
      if (s[i]) zxy = zxy * (1 - p + MOD) % MOD;
    }
    ans = ans * qkpow(1 - zxy + MOD, MOD - 2) % MOD;
    printf("%lld\n", (ans - 1 + MOD) % MOD);
  }
}
