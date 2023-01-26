#include <bits/stdc++.h>
using namespace std;
const int M = 205;
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
long long n, MOD, a1, ans, fac[M], inv[M], f[M][M][M], v[M][M][M];
long long qkpow(long long a, long long b) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}
long long dfs(long long i, long long s, long long k) {
  if (i == n) return fac[n];
  if (k == 0) return fac[n] * inv[n - i] % MOD;
  if (v[i][s][k] == a1) return f[i][s][k];
  long long &r = f[i][s][k];
  r = 0;
  v[i][s][k] = a1;
  for (long long j = (a1 - s) / k; j >= 0; j--) {
    if (k > 1 && i + j < n - a1 + 1 - k + 1) continue;
    r = (r + dfs(i + j, s + j * k, k - 1) * inv[j]) % MOD;
  }
  return r;
}
signed main() {
  n = read();
  MOD = read();
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  for (long long i = 0; i <= n; i++) inv[i] = qkpow(fac[i], MOD - 2);
  for (a1 = max(1ll, n - 30); a1 <= n; a1++)
    ans = (ans + dfs(0, 0, n + 1 - a1)) % MOD;
  printf("%lld\n", ans);
}
