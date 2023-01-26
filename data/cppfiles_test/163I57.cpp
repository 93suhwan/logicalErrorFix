#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1000;
const long long mod = 1e9 + 7;
long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b /= 2;
  }
  return ans;
}
signed main() {
  long long T, n, m, a, b, x, y, l;
  scanf("%lld", &T);
  long long G = ksm(100, mod - 2);
  printf("g = %lld\n", 18 * ksm(16, mod - 2) % mod);
  while (T--) {
    scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &x, &y, &a, &b, &l);
    long long ans = 1;
    long long now = 1;
    long long fans = 0;
    long long rx = 1;
    long long ry = 1;
    long long rx1, ry1;
    long long xa = x;
    long long ya = y;
    long long flag = 0;
    while (1) {
      long long xx = x + rx;
      long long yy = y + ry;
      if (xx <= 0 || xx > n) {
        rx = -rx;
      }
      if (yy <= 0 || yy > m) {
        ry = -ry;
      }
      if (xa == x && ya == y && flag && rx == rx1 && ry == ry1) {
        break;
      }
      if (x == a || y == b) {
        fans = (fans + now * l % mod * G % mod * ans % mod) % mod;
        now = now * (100 - l) % mod * G % mod;
      }
      ans++;
      x = x + rx;
      y = y + ry;
      if (flag == 0) {
        rx1 = rx;
        ry1 = ry;
      }
      flag = 1;
    }
    ans--;
    fans = (fans * ksm((1 - now + mod) % mod, mod - 2) % mod +
            now * ans % mod * ksm((1 - now + mod) % mod, mod - 2) - 1) %
           mod;
    printf("%lld\n", fans);
  }
  return 0;
}
