#include <bits/stdc++.h>
using namespace std;
const int N = 510, inf = 0x3f3f3f3f;
char aa[N], bb[N];
bool a[N], b[N];
int dp[N][N][N];
inline int read() {
  int ss = 0, ww = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ww = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    ss = (ss << 1) + (ss << 3) + (ch ^ 48), ch = getchar();
  return ss * ww;
}
int main() {
  int n = read(), m = read(), ans, sam, tmp;
  scanf("%s%s", aa + 1, bb + 1);
  for (int i = 1; i <= n; i++) a[i] = aa[i] - '0';
  for (int i = 1; i <= m; i++) b[i] = bb[i] - '0';
  for (int i = 1; i < m; i++) {
    for (int j = m - i + 1; j <= m; j++) {
      if (b[i] != b[j]) break;
      if (j == m) sam = i;
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n - m + 1; j++) {
      for (int k = 1; k <= m; k++) {
        tmp = (((b[k] ^ 1) == b[1]) ? 2 : 1);
        if (a[i] == b[k]) {
          if (k == m)
            dp[i + 1][j + 1][sam + 1] =
                min(dp[i + 1][j + 1][sam + 1], dp[i][j][k]);
          else
            dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k]);
          dp[i + 1][j][tmp] = min(dp[i + 1][j][tmp], dp[i][j][k] + 1);
          continue;
        }
        if (k == m)
          dp[i + 1][j + 1][sam + 1] =
              min(dp[i + 1][j + 1][sam + 1], dp[i][j][k] + 1);
        else
          dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k] + 1);
        dp[i + 1][j][tmp] = min(dp[i + 1][j][tmp], dp[i][j][k]);
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    ans = inf;
    for (int j = 1; j <= m; j++) ans = min(ans, dp[n + 1][i][j]);
    printf("%d ", (ans == inf) ? -1 : ans);
  }
  return 0;
}
