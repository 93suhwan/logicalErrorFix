#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fast(int x, int p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * x) % mod;
    x = (1LL * x * x) % mod;
    p >>= 1;
  }
  return ret;
}
void test() {
  long long n;
  scanf("%lld", &n);
  n *= 2;
  long long l, r;
  l = r = -1;
  for (long long i = 1; i <= n / i; i++) {
    if (n % i == 0) {
      long long x = i;
      long long y = n / i;
      l = x - y + 1;
      r = x + y - 1;
      if (l % 2 == 0 && r % 2 == 0) {
        l >>= 1LL;
        r >>= 1LL;
        break;
      }
    }
    if (l != -1) break;
  }
  if (l > r) swap(l, r);
  printf("%lld %lld\n", l, r);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) test();
}
