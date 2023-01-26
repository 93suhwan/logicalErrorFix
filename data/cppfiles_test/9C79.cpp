#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= k; i++) {
    int sx = 1, sy;
    scanf("%d", &sy);
    while (sx <= n) {
      if (a[sx][sy] == 1) {
        a[sx][sy] = 2;
        sy++;
      } else if (a[sx][sy] == 2) {
        sx++;
      } else {
        a[sx][sy] = 2;
        sy--;
      }
    }
    printf("%d ", sy);
  }
  return 0;
}
