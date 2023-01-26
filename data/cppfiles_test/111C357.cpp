#include <bits/stdc++.h>
int main() {
  int b, c, i, j, k, m, n, p, q, x;
  char a[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    p = m;
    x = m;
    for (k = 0; k < m; k++) {
      for (j = 0; j < p; j++) {
        printf("(");
      }
      for (j = p; j < p * 2; j++) {
        printf(")");
      }
      q = (m * 2) - (p * 2);
      for (j = 0; j < q; j++) {
        if (j % 2 == 0)
          printf("(");
        else
          printf(")");
      }
      printf("\n");
      p--;
    }
  }
  return 0;
}
