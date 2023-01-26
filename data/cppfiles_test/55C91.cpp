#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
long long k;
long long pwr(long long b, long long p, long long mod = MOD) {
  long long t = b, ans = 1;
  while (p) {
    if (p & 1) ans = (ans * t) % mod;
    t = t * t % mod;
    p = p >> 1;
  }
  return ans;
}
int main() {
  scanf("%lld", &k);
  printf("%lld\n", 6 * pwr(4, pwr(2, k, 1ll << 62) - 2) % MOD);
}
