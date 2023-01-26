#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  int x;
  while (k--) {
    scanf("%d", &x);
    for (int i = 1; i <= n; i++) {
      if (a[i][x] == 1) {
        while (a[i][x] == 1) {
          a[i][x] = 2;
          x++;
        }
        while (a[i][x] == 3) {
          a[i][x] = 2;
          x--;
        }
      } else if (a[i][x] == 3) {
        while (a[i][x] == 3) {
          a[i][x] = 2;
          x--;
        }
        while (a[i][x] == 1) {
          a[i][x] = 2;
          x++;
        }
      }
    }
    printf("%d ", x);
  }
  return 0;
}
