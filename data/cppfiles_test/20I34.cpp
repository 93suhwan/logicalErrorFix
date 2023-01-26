#include <bits/stdc++.h>
int main() {
  int a[401][401], n, m, t, i, j, k, l, b[6][6], o, sum, ans = 16;
  scanf("%d", &t);
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= 5; j++) b[i][j] = 0;
  b[1][2] = 1;
  b[1][3] = 1;
  b[2][1] = 1;
  b[2][4] = 1;
  b[3][1] = 1;
  b[3][4] = 1;
  b[4][1] = 1;
  b[4][4] = 1;
  b[5][2] = 1;
  b[5][3] = 1;
  b[1][1] = 2;
  b[1][4] = 2;
  b[5][1] = 2;
  b[5][4] = 2;
  for (o = 1; o <= t; o++) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) scanf("%1d", &a[i][j]);
    for (i = 0; i <= n - 5; i++)
      for (j = 0; j <= m - 4; j++) {
        sum = 0;
        for (k = 1; k <= 5; k++)
          for (l = 1; l <= 4; l++)
            if (b[k][l] != 2 && b[k][l] != a[i + k][j + l]) sum++;
      }
    if (sum < ans) ans = sum;
  }
  printf("%d", ans);
  return 0;
}
