#include <bits/stdc++.h>
using namespace std;
long long tans, ans[200005];
long long T, n, a[200005], p[200005], cnt[35];
long long gcd(long long x, long long y) { return (y == 0) ? x : gcd(y, x % y); }
int main() {
  long long i, temp, t, res, ff;
  scanf("%lld", &T);
  while (T--) {
    res = 0;
    ff = 1;
    tans = 0;
    memset(cnt, 0, sizeof(cnt));
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] != 0) ff = 0;
    }
    if (ff == 1) {
      for (i = 1; i <= n; i++) printf("%lld ", i);
      printf("\n");
      continue;
    }
    for (i = 1; i <= n; i++) {
      temp = a[i];
      t = 0;
      while (temp > 0) {
        if (temp % 2 == 1) cnt[t] = cnt[t] + 1;
        temp = temp / 2;
        t = t + 1;
      }
    }
    res = cnt[0];
    for (i = 1; i <= 31; i++) res = gcd(res, cnt[i]);
    for (i = 1; i <= sqrt(res); i++) {
      if (res % i == 0) {
        temp = res / i;
        ans[++tans] = i;
        if (temp != i) ans[++tans] = temp;
      }
    }
    sort(&ans[1], &ans[tans] + 1);
    for (i = 1; i <= tans; i++) printf("%lld ", ans[i]);
    printf("\n");
  }
  return 0;
}
