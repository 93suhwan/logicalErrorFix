#include <bits/stdc++.h>
using namespace std;
int const M = 43;
int i, n, m, x, y, v, i1, i2, i3, i4, i5, flag, f[44][44];
int main() {
  scanf("%d %d", &n, &m);
  n = min(n, M);
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    if (x > M || y > M) continue;
    f[x][y] = f[y][x] = 1;
  }
  for (i1 = 1; i1 <= n; i1++)
    for (i2 = i1 + 1; i2 <= n; i2++)
      for (v = f[i1][i2], i3 = i2 + 1; i3 <= n; i3++)
        for (i4 = i3 + 1; i4 <= n; i4++)
          for (i5 = i4 + 1; i5 <= n; i5++)
            if (v == f[i1][i3] && v == f[i1][i4] && v == f[i1][i5] &&
                v == f[i2][i3] && v == f[i2][i4] && v == f[i2][i5] &&
                v == f[i3][i4] && v == f[i3][i5] && v == f[i4][i5])
              return printf("%d %d %d %d %d\n", i1, i2, i3, i4, i5), 0;
  printf("-1\n");
  return 0;
}
