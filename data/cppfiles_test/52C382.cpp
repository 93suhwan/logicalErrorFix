#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int k;
int a;
long long ans;
long long pow1(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x) % 1000000007;
    ;
    x *= x;
    x %= 1000000007;
    ;
    y >>= 1;
  }
  return res;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%d", &n, &k);
    a = 0;
    ans = 0;
    while (k) {
      for (int i = 32; i; i--) {
        if ((1 << i) > k && k >= (1 << (i - 1))) {
          a = i - 1;
          break;
        }
      }
      k -= (1 << a);
      ans += pow1(n, a);
      ans %= 1000000007;
      ;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
