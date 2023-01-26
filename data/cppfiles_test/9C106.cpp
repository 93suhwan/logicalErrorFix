#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N][N], n, m, T;
int main() {
  scanf("%d %d %d", &n, &m, &T);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  while (T--) {
    int x = 1, y;
    scanf("%d", &y);
    while (x <= n) {
      if (a[x][y] == 1) {
        a[x][y] = 2;
        y++;
      } else if (a[x][y] == 2) {
        a[x][y] = 2;
        x++;
      } else {
        a[x][y] = 2;
        y--;
      }
    }
    printf("%d ", y);
  }
  puts("");
  return 0;
}
