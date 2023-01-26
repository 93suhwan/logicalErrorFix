#include <bits/stdc++.h>
int main() {
  int t;
  long long x, n, i;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &x, &n);
    if (x % 2 == 0) {
      if (n % 4 == 0)
        x = x;
      else if (n % 4 == 1)
        x = x - n;
      else if (n % 4 == 2)
        x = x + 1;
      else if (n % 4 == 3)
        x = x + 1 + n;
    } else if (x % 2 == 1) {
      if (n % 4 == 0)
        x = x;
      else if (n % 4 == 1)
        x = x + n;
      else if (n % 4 == 2)
        x = x - 1;
      else if (n % 4 == 3)
        x = x - 1 - n;
    }
    printf("%lld\n", x);
  }
}
