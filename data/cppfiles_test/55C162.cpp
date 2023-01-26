#include <bits/stdc++.h>
using namespace std;
long long ksm(long long x, long long k) {
  long long a = 1;
  while (k) {
    if (k & 1) {
      a = (a * x) % 1000000007;
    }
    x = (x * x) % 1000000007;
    k >>= 1;
  }
  return a;
}
int k;
long long ans;
int main() {
  scanf("%d", &k);
  ans = 6 * ksm(4, (1ll << k) - 2);
  printf("%lld\n", ans % 1000000007);
  return 0;
}
