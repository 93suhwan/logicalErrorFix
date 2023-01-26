#include <bits/stdc++.h>
int main() {
  int t, n, c1, c2;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    if (n % 3 == 0) {
      c1 = (n / 3);
      c2 = c1;
    } else if ((n % 3) - 2 == 0) {
      c1 = (n - 2) / 3;
      c2 = c1 + 1;
    } else {
      c2 = (n - 1) / 3;
      c1 = c2 + 1;
    }
    printf("%d %d\n", c1, c2);
  }
  return 0;
}
