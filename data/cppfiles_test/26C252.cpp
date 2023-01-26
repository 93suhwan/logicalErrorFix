#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long ans = 1;
    scanf("%lld", &n);
    if (n == 1) {
      puts("1");
      continue;
    }
    for (long long i = 3; i <= 2LL * n; ++i) ans = (ans % mod * i % mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
