#include <bits/stdc++.h>
int main() {
  long int C1, C2, t, n;
  scanf("%ld", &t);
  while (t--) {
    scanf("%ld", &n);
    if (n % 3 == 0 || n % 3 == 1) {
      C2 = n / 3;
      C1 = n - (2 * C2);
    } else if (n % 3 == 2) {
      C2 = (n / 3) + 1;
      C1 = n - (2 * C2);
    }
    printf("%ld %ld\n", C1, C2);
  }
}
