#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
const long long M = 5e3 + 5;
const long long mod = 998244353;
long long n;
long long a[N];
long long dp1[N];
long long dp2[N];
long long add(long long t1, long long t2) {
  return ((t1 % mod) + (t2 % mod)) % mod;
}
long long sub(long long t1, long long t2) {
  long long res = ((t1 % mod) - (t2 % mod)) % mod;
  while (res < 0) res += mod;
  res %= mod;
  return res;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    dp1[0] = dp2[0] = dp1[n + 1] = dp2[n + 1] = 0;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      dp1[i] = 0;
      dp2[i] = 0;
    }
    dp1[0] = 1;
    for (long long i = 1; i <= n; i++) {
      long long x = a[i];
      dp1[x + 1] = add(dp1[x + 1], dp1[x + 1]);
      dp1[x + 1] = add(dp1[x + 1], dp1[x]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp2[x - 1]);
      if (x > 0) dp2[x - 1] = add(dp2[x - 1], dp1[x - 1]);
      dp2[x + 1] = add(dp2[x + 1], dp2[x + 1]);
    }
    long long ans = 0;
    for (long long i = 0; i <= n + 1; i++) {
      ans = add(ans, dp1[i]);
      ans = add(ans, dp2[i]);
    }
    printf("%lld\n", sub(ans, 1ll));
  }
}
