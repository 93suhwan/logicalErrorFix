#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long int x, n;
    scanf("%lld%lld", &x, &n);
    switch (n % 4) {
      case 0:
        printf("%lld\n", x);
        break;
      case 1:
        if (abs(x) & 1)
          printf("%lld\n", x + n);
        else
          printf("%lld\n", x - n);
        break;
      case 2:
        if (abs(x) & 1)
          printf("%lld\n", x - 1);
        else
          printf("%lld\n", x + 1);
        break;
      case 3:
      default:
        if (abs(x) & 1)
          printf("%lld\n", x - n - 1);
        else
          printf("%lld\n", x + n + 1);
    }
  }
}
