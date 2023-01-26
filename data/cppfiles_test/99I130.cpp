#include <bits/stdc++.h>
int main() {
  long long int n, a, b, i;
  scanf("%d", &n);
  while (n--) {
    break;
    scanf("%lld %lld", &a, &b);
    if (a % 2 == 0) {
      if (b % 4 == 0) {
        printf("%lld\n", a);
        continue;
      } else {
        if ((b - 1) % 4 == 0)
          a -= b;
        else if ((b - 2) % 4 == 0)
          a = a + 1;
        else if ((b - 3) % 4 == 0)
          a = a + 1 + b;
      }
      printf("%lld\n", a);
    } else {
      if (b % 4 == 0) {
        printf("%lld\n", a);
        continue;
      } else {
        if ((b - 1) % 4 == 0)
          a += b;
        else if ((b - 2) % 4 == 0)
          a = a - 1;
        else if ((b - 3) % 4 == 0)
          a = a - 1 - b;
      }
      printf("%lld\n", a);
    }
  }
  return 0;
}
