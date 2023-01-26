#include <bits/stdc++.h>
using namespace std;
int t, n, m, f[410][410], sum[410][410], sumb[410], suma[410], summ[410], ans;
char ch[410][410];
int cal(int x, int y, int xx, int yy) {
  return sum[x][y] + sum[xx - 1][yy - 1] - sum[xx - 1][y] - sum[x][yy - 1];
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    ans = n * m + 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", ch[i] + 1);
      for (int j = 1; j <= m; ++j) f[i][j] = ch[i][j] - '0';
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + f[i][j];
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 4; j <= n; ++j) {
        sumb[0] = -160000;
        for (int k = 1; k <= m; ++k) {
          int f1 = cal(j - 1, k - 1, i + 1, 1);
          int f2 = (k - 1) - cal(i, k - 1, i, 1);
          int f3 = (k - 1) - cal(j, k - 1, j, 1);
          int f4 = (j - i - 1) - cal(j - 1, k, i + 1, k), ff4 = j - i - 1 - f4;
          if (f[i][k] == 0) ff4++;
          if (f[j][k] == 0) ff4++;
          suma[k] = f1 + f2 + f3 + f4;
          sumb[k] = f1 + f2 + f3 + ff4 - f4;
          sumb[k] = max(sumb[k], sumb[k - 1]);
          if (k >= 4) {
            ans = min(ans, suma[k] - sumb[k - 3]);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
