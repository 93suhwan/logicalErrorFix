#include <bits/stdc++.h>
using namespace std;
long long t, b, w, i, n, x, y, sum, temp, temp1, a[100005], ans;
int main() {
  scanf("%lld", &t);
  for (w = 1; w <= t; w++) {
    scanf("%lld", &n);
    x = 0;
    y = 0;
    sum = 0;
    temp = 0;
    temp1 = 0;
    ans = 0;
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      if (a[i] % 2 == 0)
        x++;
      else
        y++;
    }
    if (abs(x - y) >= 2)
      printf("-1\n");
    else if (x == y) {
      ans = 2;
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
          temp += abs(ans - i);
          ans += 2;
        }
      }
      ans = 2;
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
          temp1 += abs(ans - i);
          ans += 2;
        }
      }
      printf("%lld\n", min(abs(temp), abs(temp1)));
    } else if (x - y == 1) {
      ans = 1;
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
          temp += abs(ans - i);
          ans += 2;
        }
      }
      printf("%lld\n", abs(temp));
    } else if (y - x == 1) {
      ans = 2;
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
          temp1 += abs(ans - i);
          ans += 2;
        }
      }
      printf("%lld\n", abs(temp1));
    }
  }
}
