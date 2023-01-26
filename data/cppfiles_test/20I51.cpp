#include <bits/stdc++.h>
using namespace std;
const int N = 403;
int t, a[N][N], n, m, b[N][N], c[N][N];
int dp[N][N][N];
char s[N][N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
      for (int j = 1; j <= n; j++) {
        a[i][j] = s[i][j] - '0';
        b[i][j] = a[i][j] + b[i - 1][j];
        c[i][j] = a[i][j] + c[i][j - 1];
      }
    }
    for (int l = 0; l <= m; l++)
      for (int r = 0; r <= m; r++) dp[4][l][r] = 1 << 30;
    int ans = 1 << 30;
    for (int i = 5; i <= n; i++) {
      for (int l = 1; l <= m; l++) {
        for (int r = l + 3; r <= m; r++) {
          dp[i][l][r] += 3 - (b[i - 1][l] - b[i - 4][l]);
          dp[i][l][r] += 3 - (b[i - 1][r] - b[i - 4][r]);
          for (int j = l + 1; j < r; j++)
            dp[i][l][r] += b[i - 1][j] - b[i - 4][j];
          dp[i][l][r] += (r - l - 1) - (c[i - 4][r - 1] - c[i - 4][l]);
          dp[i][l][r] =
              min(dp[i][l][r], dp[i - 1][l][r] + 2 - a[i - 1][l] - a[i - 1][r] +
                                   (c[i - 1][r - 1] - c[i - 1][l]));
          ans = min(ans, dp[i][l][r] + (r - l - 1) - (c[i][r - 1] - c[i][l]));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
