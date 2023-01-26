#include <bits/stdc++.h>
using namespace std;
int T, n, m, k;
char c[25][25], f[25][25];
bool check(int x, int y) {
  int X1 = x, Y1 = y, X2 = x, Y2 = y, a = -1;
  while (c[X1][Y1] == '*' && c[X2][Y2] == '*') a++, X1--, Y1--, X2--, Y2++;
  return a >= k;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) f[i][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (c[i][j] != '*') continue;
        if (j - k < 1 || j + k > m || i - k < 1) continue;
        if (check(i, j)) {
          int X1 = i, Y1 = j, X2 = i, Y2 = j;
          while (c[X1][Y1] == '*' && c[X2][Y2] == '*')
            f[X1][Y1] = f[X2][Y2] = 1, X1--, Y1--, X2--, Y2++;
        }
      }
    int flag = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (c[i][j] == '*' && !f[i][j]) flag = 0;
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
