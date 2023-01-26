#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int num[N][N], a[N][N];
int p[N];
char f[N];
int sum(int i, int j, int x, int y) {
  return num[x][y] - num[i - 1][y] - num[x][j - 1] + num[i - 1][j - 1];
}
int main() {
  int t;
  int ans;
  int n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
      scanf("%s", f + 1);
      for (int j = 1; j <= m; j++) {
        a[i][j] = f[j] - '0';
        num[i][j] = num[i][j - 1] + num[i - 1][j] - num[i - 1][j - 1] + a[i][j];
      }
    }
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 4; j <= n; j++) {
        for (int k = 4; k <= m; k++) {
          p[k] = sum(i + 1, 1, j - 1, k - 1) + 2 * k - sum(i, 1, i, k) -
                 sum(j, 1, j, k) + (j - i - 1) - sum(i + 1, k, j - 1, k);
        }
        for (int k = m - 1; k >= 4; k--) {
          p[k] = min(p[k], p[k + 1]);
        }
        for (int k = 1; k + 3 <= m; k++) {
          int d = p[k + 3] - sum(i + 1, 1, j - 1, k) + (j - i - 1) -
                  sum(i + 1, k, j - 1, k);
          if (a[i][k + 3] == 0) {
            d--;
          }
          if (a[j][k + 3] == 0) {
            d--;
          }
          ans = min(ans, d);
        }
      }
    }
    printf("%d\n", ans - 1);
  }
  return 0;
}
