#include <bits/stdc++.h>
using namespace std;
const int N = 403;
int t, a[N][N], n, m, d[N][N];
int dp[2][N][N];
char s[N][N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[i][j] - '0';
        d[i][j] = a[i][j] + d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
      }
    }
    for (int l = 0; l <= m; l++)
      for (int r = l + 3; r <= m; r++) dp[0][l][r] = dp[1][l][r] = (1 << 30);
    int ans = 1 << 30;
    for (int i = 5; i <= n; i++) {
      for (int l = 1; l < m; l++) {
        for (int r = l + 3; r <= m; r++) {
          int p = i & 1;
          dp[p][l][r] = 0;
          dp[p][l][r] += 3 - (d[i - 1][l] - d[i - 4][l] - d[i - 1][l - 1] +
                              d[i - 4][l - 1]);
          dp[p][l][r] += 3 - (d[i - 1][r] - d[i - 4][r] - d[i - 1][r - 1] +
                              d[i - 4][r - 1]);
          dp[p][l][r] +=
              d[i - 1][r - 1] - d[i - 1][l] - d[i - 4][r - 1] + d[i - 4][l];
          dp[p][l][r] += (r - l - 1) - (d[i - 4][r - 1] - d[i - 4][l] -
                                        d[i - 5][r - 1] + d[i - 5][l]);
          dp[p][l][r] =
              min(dp[p][l][r], dp[p ^ 1][l][r] + 2 - a[i - 1][l] - a[i - 1][r] +
                                   (d[i - 1][r - 1] - d[i - 1][l] -
                                    d[i - 2][r - 1] + d[i - 2][l]));
          ans = min(
              ans, dp[p][l][r] + (r - l - 1) -
                       (d[i][r - 1] - d[i][l] - d[i - 1][r - 1] + d[i - 1][l]));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
