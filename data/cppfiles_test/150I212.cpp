#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[110];
int main(void) {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int chk[10] = {
        0,
    };
    for (int i = 1; i <= n; i++) chk[a[i] % 3] = 1;
    int ans = 0;
    if (!chk[1] && !chk[2]) {
      for (int i = 1; i <= n; i++) ans = max(a[i] / 3, ans);
    } else if (chk[1] && !chk[2]) {
      for (int i = 1; i <= n; i++) ans = max(ans, a[i] / 3);
      ans++;
    } else if (!chk[1] && chk[2]) {
      for (int i = 1; i <= n; i++) ans = max(ans, a[i] / 3);
      ans++;
    } else {
      int ff = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] == 1) ff = 1;
      }
      if (ff) {
        for (int i = 1; i <= n; i++) {
          if (a[i] % 3 == 0)
            ans = max(ans, a[i] / 3 - 1);
          else
            ans = max(ans, a[i] / 3);
        }
        ans += 2;
      } else {
        int hubo = 0;
        for (int i = 1; i <= n; i++) {
          if (a[i] % 3 == 1)
            hubo = max(hubo, (a[i] - 4) / 3);
          else
            hubo = max(hubo, a[i] / 3);
        }
        hubo += 2;
        for (int i = 1; i <= n; i++) {
          if (a[i] % 3 == 1)
            ans = max(ans, (a[i] - 4) / 3);
          else if (a[i] % 3 == 0)
            ans = max(ans, a[i] / 3 - 2);
          else
            ans = max(ans, (a[i] - 2) / 3);
        }
        ans += 3;
        ans = min(ans, hubo);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
