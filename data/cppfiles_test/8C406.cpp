#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    int c1 = 0, c2 = 0;
    c1 = n / 3;
    c2 = c1;
    int res;
    res = n % 3;
    if (res == 1) {
      c1++;
    } else if (res == 2) {
      c2++;
    }
    printf("%d %d\n", c1, c2);
  }
  return 0;
}
