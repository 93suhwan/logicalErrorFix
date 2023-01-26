#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9 + 7;
long long pow(long long x, long long n, long long p) {
  long long ans = 1 % p;
  for (; n; n >>= 1) {
    if (n & 1) ans = ans * x % p;
    x = x * x % p;
  }
  return ans;
}
signed main() {
  long long n;
  scanf("%lld", &n);
  long long ans = 6 * pow(4, (1ll << n) - 2, mo) % mo;
  printf("%lld\n", ans);
  return 0;
}
