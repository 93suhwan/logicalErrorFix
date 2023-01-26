#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int x1, x2, p1, p2;
  while (n--) {
    scanf("%d %d %d %d", &x1, &p1, &x2, &p2);
    int l1 = 0, l2 = 0;
    for (int a = x1; a; a /= 10) l1++;
    for (int b = x2; b; b /= 10) l2++;
    if (l1 + p1 > l2 + p2) {
      printf(">\n");
      continue;
    } else if (l1 + p1 < l2 + p2) {
      printf("<\n");
      continue;
    } else {
      if (l1 > l2)
        for (int l = 0; l < l1 - l2; l++) x2 *= 10;
      else if (l1 < l2)
        for (int l = 0; l < l2 - l1; l++) x1 *= 10;
      if (x1 > x2)
        printf(">\n", x1, x2);
      else if (x1 < x2)
        printf("<\n", x1, x2);
      else
        printf("=\n", x1, x2);
    }
  }
  return 0;
}
