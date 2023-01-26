#include <bits/stdc++.h>
using namespace std;
int a[300005], b[300005];
int main() {
  int i, k, t, x, y, n, q, num1, num2;
  string s;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d", &n, &q);
    cin >> s;
    s = " " + s;
    for (k = 0; k <= n; k++) a[k] = b[k] = 0;
    if (s[1] == '+')
      a[1] = a[2] = 1;
    else
      a[1] = a[2] = -1;
    if (s[2] == '+')
      b[2] = 1;
    else
      b[2] = -1;
    for (k = 3; k <= n; k++) {
      if (k % 2 == 1) {
        if (s[k] == '+')
          a[k] = a[k - 2] + 1;
        else
          a[k] = a[k - 2] - 1;
        b[k] = b[k - 1];
      } else {
        if (s[k] == '+')
          b[k] = b[k - 2] + 1;
        else
          b[k] = b[k - 2] - 1;
        a[k] = a[k - 1];
      }
    }
    for (k = 0; k < q; k++) {
      scanf("%d %d", &x, &y);
      num1 = a[y] - a[x - 1];
      num2 = b[y] - b[x - 1];
      if (abs(num1 - num2) > 2) {
        if (abs(num1 - num2) % 2 == 1)
          printf("1\n");
        else
          printf("2\n");
      } else
        printf("%d\n", abs(num1 - num2));
    }
  }
  return 0;
}
