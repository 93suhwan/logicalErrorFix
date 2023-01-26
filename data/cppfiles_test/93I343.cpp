#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    n--;
    if (k > 2e9 || k * (k + 1) / 2 >= n) {
      long long l = 0, r = k;
      while (l < r) {
        long long mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 >= n)
          r = mid;
        else
          l = mid + 1;
      }
      printf("%lld\n", l);
    } else {
      long long ans = k;
      n -= k * (k + 1) / 2;
      printf("%lld\n", ans + (n - 1) / k + 1);
    }
  }
  return 0;
}
