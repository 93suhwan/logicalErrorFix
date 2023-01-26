#include <bits/stdc++.h>
using namespace std;
const int N = 505, inf = 0x3f3f3f3f;
int a[N], b[N], l1, l2, nxt[N], f[N];
int dp[N][N][N];
inline void kmp() {
  nxt[1] = 0, f[0] = -1;
  int j = 0;
  for (int i = (2); i <= (l2); i++) {
    while (j != 0 && b[j + 1] != b[i]) j = nxt[j];
    if (b[j + 1] == b[i]) j++;
    nxt[i] = j;
    f[i] = b[nxt[i] + 1] == b[i + 1] ? f[nxt[i]] : nxt[i];
  }
}
char s[N];
inline void chkmin(int &x, int y) { x = min(x, y); }
int main() {
  scanf("%d%d", &l1, &l2);
  scanf("%s", s + 1);
  for (int i = (1); i <= (l1); i++) a[i] = s[i] - '0';
  scanf("%s", s + 1);
  for (int i = (1); i <= (l2); i++) b[i] = s[i] - '0';
  kmp(), memset(dp, inf, sizeof dp), dp[0][0][0] = 0;
  for (int i = (0); i <= (l1 - 1); i++)
    for (int j = (0); j <= (l2 - 1); j++)
      for (int k = (0); k <= (l1 - l2 + 1); k++) {
        int w = dp[i][j][k];
        if (w >= inf) continue;
        if (a[i + 1] == b[j + 1]) {
          if (j + 1 == l2)
            chkmin(dp[i + 1][nxt[l2]][k + 1], w);
          else
            chkmin(dp[i + 1][j + 1][k], w);
          chkmin(dp[i + 1][f[j] + 1][k], w + 1);
        } else {
          chkmin(dp[i + 1][f[j] + 1][k], w);
          if (j + 1 == l2)
            chkmin(dp[i + 1][nxt[l2]][k + 1], w + 1);
          else
            chkmin(dp[i + 1][j + 1][k], w + 1);
        }
      }
  for (int k = (0); k <= (l1 - l2 + 1); k++) {
    int mn = inf;
    for (int i = (0); i <= (l2 - 1); i++) {
      chkmin(mn, dp[l1][i][k]);
    }
    printf("%d ", mn == inf ? -1 : mn);
  }
  return 0;
}
