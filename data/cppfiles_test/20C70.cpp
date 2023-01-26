#include <bits/stdc++.h>
using namespace std;
int T, n, m, f[410][410], g[410][410], tmp, ans, mx, j, nw;
char s[410];
int cal(int a1, int b1, int a2, int b2) {
  return g[a2][b2] - g[a1 - 1][b2] - g[a2][b1 - 1] + g[a1 - 1][b1 - 1];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m), ans = 410 * 410;
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      for (int j = 1; j <= m; j++)
        if (s[j - 1] == '1')
          f[i][j] = 1;
        else
          f[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + f[i][j];
    for (int p1 = 1; p1 <= n; p1++)
      for (int p2 = p1 + 4; p2 <= n; p2++) {
        mx = -410 * 410;
        for (int i = 4; i <= m; i++) {
          nw = cal(p1 + 1, 1, p2 - 1, i - 1) +
               (p2 - p1 - 1 - cal(p1 + 1, i, p2 - 1, i)) +
               (i - 1 - cal(p1, 1, p1, i - 1)) +
               (i - 1 - cal(p2, 1, p2, i - 1));
          j = i - 3;
          tmp = (j - cal(p1, 1, p1, j)) + (j - cal(p2, 1, p2, j)) +
                cal(p1 + 1, 1, p2 - 1, j - 1) -
                (p2 - p1 - 1 - 2 * cal(p1 + 1, j, p2 - 1, j));
          mx = max(mx, tmp);
          ans = min(ans, nw - mx);
        }
      }
    printf("%d\n", ans);
  }
}
