#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const int maxn = 3e5 + 10;
long long k;
long long pwr(long long b, long long p) {
  long long t = b, ans = 1;
  while (p) {
    if (p & 1) ans = (ans * t) % MOD;
    t = t * t % MOD;
    p = p >> 1;
  }
  return ans;
}
int main() {
  scanf("%d", &k);
  printf("%lld\n", (6 * pwr(4, pwr(2, k) - 2) % MOD + MOD) % MOD);
}
