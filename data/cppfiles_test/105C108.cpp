#include <bits/stdc++.h>
using namespace std;
int T, n, i, tt, k, x, aa, gg, j, a[3005], c[3005], dp[3005][3005],
    pos[3005][22];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (i = 1; i <= n; ++i) c[i] = 0;
    for (i = 1; i <= n; ++i) cin >> a[i], pos[a[i]][++c[a[i]]] = i;
    for (i = 1; i <= n; ++i) dp[i][i] = 0;
    for (j = 1; j <= n; ++j) {
      for (i = 1; i <= n - j; ++i) {
        k = j + i;
        if (a[i] == a[k]) {
          if (a[i] == a[i + 1]) {
            dp[i][k] = dp[i + 1][k];
          } else if (a[k - 1] == a[k]) {
            dp[i][k] = dp[i][k - 1];
          } else
            dp[i][k] = dp[i + 1][k - 1] + 1;
          for (int j = 1; j <= c[a[i]]; ++j) {
            if (pos[a[i]][j] >= i && pos[a[i]][j] < k) {
              dp[i][k] =
                  min(dp[i][k], dp[i][pos[a[i]][j]] + dp[pos[a[i]][j]][k]);
            }
          }
        } else
          dp[i][k] = 1000000;
        for (int j = 1; j <= c[a[i]]; ++j) {
          if (pos[a[i]][j] >= i && pos[a[i]][j] < k) {
            dp[i][k] = min(dp[i][k],
                           dp[i][pos[a[i]][j]] + 1 + dp[pos[a[i]][j] + 1][k]);
          }
        }
      }
    }
    cout << dp[1][n] << "\n";
  }
}
