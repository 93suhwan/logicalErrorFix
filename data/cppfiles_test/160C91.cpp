#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d", &x);
  for (y = 0; y < x; y++) {
    int i, j, n, m, rb, cb, rd, cd;
    scanf("%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd);
    if (rb == rd || cb == cd)
      printf("0\n");
    else if (rb < rd && cb < cd) {
      if (rd - rb < cd - cb) {
        printf("%d\n", rd - rb);
      } else
        printf("%d\n", cd - cb);
    } else if (rb > rd && cb > cd) {
      if (n - rd + n - rb > m - cd + m - cb) {
        printf("%d\n", m - cd + m - cb);
      } else
        printf("%d\n", n - rd + n - rb);
    } else if (rb < rd && cb > cd) {
      if (rd - rb > m - cd + m - cb)
        printf("%d\n", m - cd + m - cb);
      else
        printf("%d\n", rd - rb);
    } else if (rb > rd && cb < cd) {
      if (n - rd + n - rb > cd - cb) {
        printf("%d\n", cd - cb);
      } else
        printf("%d\n", n - rd + n - rb);
    }
  }
  return 0;
}
