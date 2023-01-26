#include <bits/stdc++.h>
using namespace std;
const int MAXN = 410;
int n, m;
int a[MAXN];
int b[MAXN];
char ch[MAXN][MAXN];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch[i] + 1);
    }
    int ans = -1, mn;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[j] = 0;
        b[j] = 0;
      }
      for (int j = i + 1; j <= n; j++) {
        if (j >= i + 4) {
          mn = -1;
          for (int k = 1; k <= m; k++) {
            if (k >= 4) {
              int s = a[k - 1] + a[k - 2] + b[k - 3] + (ch[i][k - 1] == '0') +
                      (ch[j][k - 1] == '0') + (ch[i][k - 2] == '0') +
                      (ch[j][k - 2] == '0');
              if (mn == -1)
                mn = s;
              else
                mn = min(mn, s);
            }
            if (mn != -1) {
              if (ans == -1)
                ans = mn + b[k];
              else
                ans = min(ans, mn + b[k]);
              mn = mn + a[k];
              mn = mn + ((ch[i][k] == '0')) + ((ch[j][k] == '0'));
            }
          }
        }
        for (int k = 1; k <= m; k++)
          a[k] = a[k] + ((ch[j][k] == '1')), b[k] = b[k] + ((ch[j][k] == '0'));
      }
    }
    printf("%d\n", ans);
  }
}
