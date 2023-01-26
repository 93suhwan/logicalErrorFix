#include <bits/stdc++.h>
int main() {
  int C1, C2, t, n;
  scanf("%d\n", &t);
  scanf("%d", &n);
  while (t--) {
    if (n % 3 == 0 || n % 3 == 1) {
      C2 = n / 3;
      C1 = n - (2 * C2);
      printf("%d %d", C1, C2);
    } else if (n % 3 == 2) {
      C2 = (n / 3) + 1;
      C1 = n - (2 * C2);
      printf("%d %d", C1, C2);
    }
  }
}
