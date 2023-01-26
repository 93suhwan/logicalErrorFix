#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[5000 + 5][5000 + 5];
signed main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  while (k--) {
    int ci;
    scanf("%d", &ci);
    int nx = 1, ny = ci;
    while (nx != n) {
      int x = nx, y = ny;
      if (a[x][y] == 1) nx = x, ny = y + 1;
      if (a[x][y] == 2) nx = x + 1, ny = y;
      if (a[x][y] == 3) nx = x, ny = y - 1;
      a[x][y] = 2;
    }
    a[nx][ny] = 2;
    printf("%d ", ny);
  }
  return 0;
}
