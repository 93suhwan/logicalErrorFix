#include <bits/stdc++.h>
using namespace std;
const int N = 500;
char a[N + 5][N + 5];
int ans[N + 5][N + 5];
int nx[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 'X') {
        int tot = 0;
        for (int k = 0; k <= 3; k++) {
          int dx = i + nx[k][0];
          int dy = j + nx[k][1];
          if (dx <= 0 || dx > n || dy <= 0 || dy > m) continue;
          if (a[dx][dy] == '.') tot++;
        }
        if (tot % 2) {
          printf("NO");
          return 0;
        }
        ans[i][j] = tot / 2 * 5;
      }
  printf("YES\n");
  int temp = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.')
        ans[i][j] = temp;
      else if (a[i - 1][j] == 'X')
        temp ^= 5;
    }
    temp ^= 5;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
  return 0;
}
