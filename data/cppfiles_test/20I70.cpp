#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
int n, m, t;
int a[maxn][maxn], s[maxn][maxn], cul[maxn];
int ask(int a, int b, int x, int y) {
  if (b > y) return 0;
  return s[x][y] - s[x][b - 1] - s[a - 1][y] + s[a - 1][b - 1];
}
int main() {
  scanf("%d", &t);
  while (t--) {
    int ans = 1 << 30;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) scanf("%1d", &a[i][j]);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    for (int i = 1; i <= n; ++i)
      for (int r = i + 4; r <= n; ++r) {
        int cx = 0, cy = 0;
        for (int j = 1; j <= m; ++j) {
          if (a[i][j] == 0) ++cx;
          if (a[r][j] == 0) ++cy;
          cul[j] = ask(i + 1, 1, r - 1, j - 1) + cx + cy -
                   (r - i - 1 - ask(i + 1, j, r - 1, j));
        }
        cul[0] = -(1 << 30);
        for (int j = 1; j <= m; ++j) {
          if (j >= 4) {
            ans =
                min(ans, cul[j] - cul[j - 3] - (a[i][j] == 0) - (a[r][j] == 0) +
                             2 * (r - i - 1 - ask(i + 1, j, r - 1, j)));
          }
          cul[j] = max(cul[j], cul[j - 1]);
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
