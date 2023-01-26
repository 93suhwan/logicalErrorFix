#include <bits/stdc++.h>
using namespace std;
char str[405][405];
int pre[405][405], now[405];
int main() {
  int t, n, m, i, j, k, p, ans, mn;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    ans = n * m;
    for (i = 1; i <= (n); i++) {
      scanf("%s", str[i] + 1);
      for (j = 1; j <= (m); j++) pre[i][j] = pre[i][j - 1] + (str[i][j] == '1');
    }
    for (i = 1; i <= (m - 3); i++)
      for (j = i + 3; j <= (m); j++) {
        for (k = 1; k <= (4); k++)
          now[k] = now[k - 1] + (str[k][i] == '0') + (str[k][j] == '0') +
                   pre[k][j - 1] - pre[k][i];
        mn = now[4] - now[1] + (j - 1 - i) - (pre[1][j - 1] - pre[1][i]);
        for (k = 5; k <= (n); k++) {
          ans = ((ans) < (mn + (j - 1 - i) - (pre[k][j - 1] - pre[k][i]))
                     ? ans
                     : mn + (j - 1 - i) - (pre[k][j - 1] - pre[k][i]));
          p = (str[k][i] == '0') + (str[k][j] == '0') + pre[k][j - 1] -
              pre[k][i];
          now[k] = now[k - 1] + p;
          mn = ((mn + p) < (now[k] - now[k - 3] + (j - 1 - i) -
                            (pre[k - 3][j - 1] - pre[k - 3][i]))
                    ? mn + p
                    : now[k] - now[k - 3] + (j - 1 - i) -
                          (pre[k - 3][j - 1] - pre[k - 3][i]));
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
