#include <bits/stdc++.h>
using namespace std;
int tac, n, m;
char c[410][410];
int a[410][410], pre[410][410];
int res;
int main() {
  scanf("%d", &tac);
  while (tac--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", c[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++) a[i][j] = 1e9;
    for (int i = 0; i < n; i++) {
      pre[i][0] = 0;
      for (int j = 0; j < m; j++) pre[i][j + 1] = pre[i][j] + c[i][j] - '0';
    }
    res = 1e9;
    for (int i = 0; i < n; i++) {
      if (i >= 4) {
        for (int j = 0; j < m; j++) {
          for (int k = j; k < m; k++) {
            if (k - j + 1 < 4) continue;
            int r = 0;
            r += (k - j - 1) - (pre[i - 4][k] - pre[i - 4][j + 1]);
            for (int it = i - 3; it < i; it++) {
              r += (c[it][j] == '0' ? 1 : 0) + (c[it][k] == '0' ? 1 : 0);
              r += pre[it][k] - pre[it][j + 1];
            }
            a[j][k] = min(a[j][k], r);
          }
        }
      }
      for (int j = 0; j < m; j++) {
        for (int k = j; k < m; k++) {
          if (k - j + 1 < 4) continue;
          res = min(res, a[j][k] + (k - j - 1) - (pre[i][k] - pre[i][j + 1]));
          a[j][k] += (c[i][j] == '0' ? 1 : 0) + (c[i][k] == '0' ? 1 : 0);
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
