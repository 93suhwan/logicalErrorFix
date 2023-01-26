#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long power(long long a, long long x) {
  a = (a + mod) % mod;
  long long ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;
}
long long inv(long long a) { return power(a, mod - 2); }
int main() {
  long long inv100 = inv(100);
  int t, n, m, rb, cb, rd, cd;
  long long p;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d%d%lld", &n, &m, &rb, &cb, &rd, &cd, &p);
    p = p * inv100 % mod;
    int dr = 1, sr, dc = 1, sc;
    if (rb + dr > n) dr = -1;
    if (cb + dc > m) dc = -1;
    sr = dr;
    sc = dc;
    long long suma = 0, sumb = 0;
    int nowx = rb, nowy = cb;
    long long times = 0, step = 0;
    while (1) {
      if (step && nowx == rb && nowy == cb && dr == sr && dc == sc) break;
      step++;
      if (nowx == rd || nowy == cd) {
        long long temp = power(1 - p + mod, times);
        suma = (suma + (step - 1) * p % mod * temp % mod) % mod;
        sumb = (sumb + p * temp % mod) % mod;
        times++;
      }
      nowx += dr;
      nowy += dc;
      if (nowx + dr > n)
        dr = -dr;
      else if (nowx + dr <= 0)
        dr = -dr;
      if (nowy + dc > m)
        dc = -dc;
      else if (nowy + dc <= 0)
        dc = -dc;
    }
    long long q = power(1 - p + mod, times);
    long long acoef = inv(1 - q + mod),
              bcoef = q * power(inv(1 - q + mod), 2) % mod;
    long long ans =
        (suma * acoef % mod + sumb * step % mod * bcoef % mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
