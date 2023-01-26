#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  bool f = true;
  long long x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = false;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  if (f) return x;
  return ~(--x);
}
inline void write(const long long &x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void print(const long long &x) {
  x < 0 ? putchar('-'), write(~(x - 1)) : write(x);
  putchar('\n');
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
long long n, q;
const int MAXN = 3e6 + 7;
const long long mod = 1e9 + 7;
inline long long add(long long x, long long y) {
  return (x += y) < mod ? x : x - mod;
}
inline long long dec(long long x, long long y) {
  return (x -= y) < 0 ? x + mod : x;
}
inline long long ksm(long long d, long long tim) {
  long long rest = 1;
  while (tim) {
    if (tim & 1) rest = rest * d % mod;
    d = d * d % mod;
    tim >>= 1;
  }
  return rest;
}
long long fac[MAXN], ifac[MAXN], inv[MAXN];
void init(int n = MAXN - 1) {
  fac[0] = 1;
  for (register int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = ksm(fac[n], mod - 2);
  for (register int i = n - 1; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  for (register int i = n; i; --i) inv[i] = ifac[i] * fac[i - 1] % mod;
}
inline long long C(long long x, long long y) {
  if (x < y) return 0;
  return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
long long f[MAXN], sum[MAXN][4];
int main() {
  init();
  n = read(), q = read();
  f[0] = 1;
  sum[1][1] = 1ll * (3 * n - 1) * n % mod * ifac[2] % mod;
  sum[1][2] = 1ll * (3 * n + 1) * n % mod * ifac[2] % mod;
  sum[1][3] = 1ll * (3 * n + 3) * n % mod * ifac[2] % mod;
  for (register int i = 2; i <= 3 * n; ++i) {
    long long x = sum[i - 1][1] * i % mod, y = sum[i - 1][2] * i % mod,
              tot = fac[3 * n + 1] * ifac[3 * n - i] % mod * inv[i + 1] % mod;
    sum[i][1] = dec(tot, add(add(x, x), y)) * inv[3] % mod;
    sum[i][2] = add(sum[i][1], x);
    sum[i][3] = add(sum[i][2], y);
  }
  for (register int i = 1; i <= q; ++i) {
    int x = read();
    print(sum[x][3] * ifac[x] % mod);
  }
  return 0;
}
