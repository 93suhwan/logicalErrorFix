#include <bits/stdc++.h>
using namespace std;
int const N = 14;
int const mod = 1e9 + 7;
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
  long long t, ret;
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ret = ext_gcd(b, a % b, x, y);
  t = x, x = y, y = t - a / b * y;
  return ret;
}
long long inv(long long a, long long b, long long c) {
  long long x, y;
  ext_gcd(a, c, x, y);
  return (x * b % c + c) % c;
}
int n;
long long a[N];
long long ff[1 << N], ga[1 << N][N + 1], gb[1 << N];
long long g(int x, int y) {
  long long da = ga[x][__builtin_popcount(y)];
  long long db = inv(gb[x ^ y], gb[x] * gb[y] % mod, mod);
  return da * db % mod;
}
long long f(int msk, int all) {
  if (ff[msk] != -1) return ff[msk];
  long long ans = g(msk, all ^ msk);
  for (int i = (msk - 1) & msk; i > 0; i = (i - 1) & msk) {
    ans -= f(i, all) * g(msk ^ i, all ^ msk);
    ans %= mod;
  }
  return ff[msk] = ans;
}
void ginit(int n) {
  for (int i = 0; i < (1 << n); ++i) {
    ga[i][0] = gb[i] = 1;
    long long z = 1;
    for (int j = 0; j < (n); ++j)
      if (i >> j & 1) z = z * a[j] % mod;
    for (int j = 1; j <= (n); ++j) ga[i][j] = ga[i][j - 1] * z % mod;
    for (int j = 0; j < (n); ++j)
      for (int k = j + 1; k < n; ++k) {
        if ((i >> j & 1) && (i >> k & 1)) {
          gb[i] = gb[i] * (a[j] + a[k]) % mod;
        }
      }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < (1 << n); ++i) ff[i] = -1;
  ginit(n);
  long long ans = 0;
  int all = (1 << n) - 1;
  for (int i = 1; i <= (all); ++i) {
    ans += f(i, all) * __builtin_popcount(i);
    ans %= mod;
  }
  ans = (ans + mod) % mod;
  printf("%lld\n", ans);
  return 0;
}
