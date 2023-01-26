#include <bits/stdc++.h>
using namespace std;
const long long N = 1000010, k = 2, mod = 1e9 + 7;
long long n, a[N], q, qza[N], c[N][k + 1], qz[N][k + 1], qzz[N], cc[k + 1],
    inv[k + 1];
long long ksm(long long x, long long y) {
  long long tt = 1;
  while (y) {
    if (y & 1) tt = tt * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return tt;
}
long long C(long long x, long long y) {
  if (x < y || x < 0 || y < 0) return 0;
  return cc[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main() {
  scanf("%lld%lld", &n, &q);
  cc[0] = 1;
  for (long long i = 1; i <= k; i++) cc[i] = cc[i - 1] * i % mod;
  inv[k] = ksm(cc[k], mod - 2);
  for (long long i = k - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    qza[i] = (qza[i - 1] + ksm(a[i], k)) % mod;
    qzz[i] = (qzz[i - 1] + a[i]) % mod;
  }
  qz[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    c[i][0] = 1;
    qz[i][0] = (qz[i - 1][0] + c[i][0]) % mod;
    for (long long j = 1; j <= k; j++)
      c[i][j] = c[i][j - 1] * i % mod,
      qz[i][j] = (qz[i - 1][j] + c[i][j]) % mod;
  }
  for (long long i = 1, l, r, d; i <= q; i++) {
    scanf("%lld%lld%lld", &l, &r, &d);
    long long aa = (qza[r] - qza[l - 1] + mod) % mod;
    long long ah = (qzz[r] - qzz[l - 1] + mod) % mod, len = r - l + 1;
    long long ba = (ah - (len * (len - 1) / 2) % mod * d % mod + mod) *
                   ksm(len, mod - 2) % mod;
    long long tot = 0;
    for (long long j = 0; j <= k; j++) {
      tot = (tot + C(k, j) * ksm(ba, k - j) % mod * ksm(d, j) % mod *
                       qz[len - 1][j] % mod) %
            mod;
    }
    if (tot == aa)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
