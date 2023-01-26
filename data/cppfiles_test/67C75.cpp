#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 50;
long long fac[maxn];
long long inv[maxn];
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long ans = 1;
  long long k = a;
  while (b) {
    if (b & 1) ans = ans * k % mod;
    k = k * k % mod;
    b >>= 1;
  }
  return (ans + mod) % mod;
}
void init(long long xx) {
  long long it;
  fac[0] = 1;
  inv[0] = 1;
  fac[1] = 1;
  inv[1] = 1;
  for (long long i = 2; i <= xx; i++)
    fac[i] = fac[i - 1] * i % mod,
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
  for (long long i = 1; i <= xx; i++) inv[i] = inv[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  if (n < m || m < 0) return 0;
  return (fac[n] * inv[m] % mod * inv[n - m] % mod + mod) % mod;
}
signed main() {
  init(1005);
  long long n;
  double xx;
  cin >> n >> xx;
  for (long long x = 0; x <= n; x++) {
    long long p0 = C(n - x, 3);
    long long p1 = C(n - x, 2) * x;
    long long p2 = C(x, 2) * (n - x);
    long long p3 = C(x, 3);
    double p = (0.5 * p1 + p2 + p3) / (1.0 * p0 + p1 + p2 + p3);
    if (p - xx > 1e-10 || abs(p - xx) < 1e-10) {
      printf("%lld\n", x);
      return 0;
    }
  }
}
