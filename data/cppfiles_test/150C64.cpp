#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
long long a[110];
int main(void) {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long chk[10] = {
        0,
    };
    for (long long i = 1; i <= n; i++) chk[a[i] % 3] = 1;
    long long ans = 0;
    if (!chk[1] && !chk[2]) {
      for (long long i = 1; i <= n; i++) ans = max(a[i] / 3, ans);
    } else if (chk[1] && !chk[2]) {
      for (long long i = 1; i <= n; i++) ans = max(ans, a[i] / 3);
      ans++;
    } else if (!chk[1] && chk[2]) {
      for (long long i = 1; i <= n; i++) ans = max(ans, a[i] / 3);
      ans++;
    } else {
      long long ff = 0;
      for (long long i = 1; i <= n; i++) {
        if (a[i] == 1) ff = 1;
      }
      if (ff) {
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 0)
            ans = max(ans, a[i] / 3 - 1);
          else
            ans = max(ans, a[i] / 3);
        }
        ans += 2;
      } else {
        long long hubo2 = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 0)
            hubo2 = max(hubo2, a[i] / 3 - 1);
          else
            hubo2 = max(hubo2, a[i] / 3);
        }
        hubo2 += 2;
        long long hubo = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 1)
            hubo = max(hubo, (a[i] - 4) / 3);
          else
            hubo = max(hubo, a[i] / 3);
        }
        hubo += 2;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 1)
            ans = max(ans, (a[i] - 4) / 3);
          else if (a[i] % 3 == 0)
            ans = max(ans, a[i] / 3 - 2);
          else
            ans = max(ans, (a[i] - 2) / 3);
        }
        ans += 3;
        ans = min(ans, hubo);
        ans = min(ans, hubo2);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
