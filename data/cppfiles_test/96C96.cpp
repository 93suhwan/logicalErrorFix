#include <bits/stdc++.h>
using namespace std;
long long n, x, ans, fac[505], ifac[505], f[505][505];
inline long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 1) + (s << 3) + ch - '0';
    ch = getchar();
  }
  return s * f;
}
inline long long C(long long n, long long m, long long p = 998244353ll) {
  return (m > n) ? 0 : fac[n] * ifac[m] % p * ifac[n - m] % p;
}
inline long long Qpow(long long a, long long b, long long p = 998244353ll) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % p;
    a = a * a % p, b >>= 1;
  }
  return c;
}
inline void get_fac(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % 998244353ll;
  ifac[n] = Qpow(fac[n], 998244353ll - 2);
  for (long long i = n; i; --i) ifac[i - 1] = ifac[i] * i % 998244353ll;
}
signed main() {
  n = read(), x = read(), get_fac(n);
  f[n][0] = 1;
  for (long long i = n; i > 1; --i)
    for (long long j = 0; j <= x; ++j)
      for (long long k = i, nj = min(x, j + i - 1), bas = 1; k >= 0; --k) {
        f[k][nj] = (f[k][nj] +
                    C(i, i - k) * bas % 998244353ll * f[i][j] % 998244353ll) %
                   998244353ll;
        bas = bas * (nj - j) % 998244353ll;
      }
  for (long long i = 1; i <= x; ++i) ans = (ans + f[0][i]) % 998244353ll;
  printf("%lld\n", ans);
  return 0;
}
