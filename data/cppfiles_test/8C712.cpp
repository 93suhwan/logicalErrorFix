#include <bits/stdc++.h>
int main(void) {
  int t, c1, c2, n;
  int diffprev, diff_curr;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    if (n % 3 == 0) {
      c1 = n / 3;
      c2 = c1;
    } else if (n % 3 == 1) {
      c1 = n / 3;
      c2 = c1;
      c1 = ++c1;
    } else {
      c1 = n / 3;
      c2 = c1 + 1;
    }
    printf("%d %d\n", c1, c2);
  }
}
