#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d", &x);
  for (y = 0; y < x; y++) {
    int i, j, n, m, rb, cb, rd, cd, t = 0;
    scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);
    if (rb == rd || cb == cd)
      printf("0\n");
    else if (rb < rd && cb < cd) {
      if (rd - rb < cd - cb) {
        printf("%d\n", rd - rb);
      } else
        printf("%d\n", cd - cb);
    } else if (rb > rd && cb > cd) {
      if (m - rd + m - rb > n - cd + n - cb) {
        printf("%d\n", n - cd + n - cb);
      } else
        printf("%d\n", m - rd + m - rb);
    } else if (rb < rd && cb > cd) {
      if (rd - rb > n - cd + n - cb)
        printf("%d\n", n - cd + n - cb);
      else
        printf("%d\n", rd - rb);
    } else if (rb > rd && cb < cd) {
      if (m - rd + m - rb > cd - cb) {
        printf("%d\n", cd - cb);
      } else
        printf("%d\n", m - rd + m - rb);
    }
  }
  return 0;
}
