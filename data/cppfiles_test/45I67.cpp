#include <bits/stdc++.h>
using namespace std;
int t, b, w, i, n, x, y, sum, temp, temp1, a[100005];
int main() {
  scanf("%d", &t);
  for (w = 1; w <= t; w++) {
    scanf("%d", &n);
    x = 0;
    y = 0;
    sum = 0;
    temp = 0;
    temp1 = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] % 2 == 0)
        x++;
      else
        y++;
    }
    if (abs(x - y) >= 2)
      printf("-1\n");
    else if (x == y) {
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0 && i % 2 == 0)
          temp += i;
        else if (a[i] % 2 == 1 && i % 2 == 1)
          temp -= i;
      }
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 1 && i % 2 == 0)
          temp1 += i;
        else if (a[i] % 2 == 0 && i % 2 == 1)
          temp1 -= i;
      }
      printf("%d\n", min(abs(temp), abs(temp1)));
    } else if (x - y == 1) {
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 0 && i % 2 == 0)
          temp += i;
        else if (a[i] % 2 == 1 && i % 2 == 1)
          temp -= i;
      }
      printf("%d\n", abs(temp));
    } else if (y - x == 1) {
      for (i = 1; i <= n; i++) {
        if (a[i] % 2 == 1 && i % 2 == 0)
          temp1 += i;
        else if (a[i] % 2 == 0 && i % 2 == 1)
          temp1 -= i;
      }
      printf("%d\n", abs(temp1));
    }
  }
}
