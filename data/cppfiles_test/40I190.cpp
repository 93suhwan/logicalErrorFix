#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[3][maxn], dp[3][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, m, i, j, p;
  cin >> t;
  while (t--) {
    cin >> m;
    p = m;
    for (i = 1; i <= 2; i++)
      for (j = 1; j <= m; j++) cin >> a[i][j], dp[i][j] = 0;
    dp[2][m] = a[2][m];
    dp[1][m] = dp[2][m] + a[1][m];
    for (i = m - 1; i; i--) dp[2][i] = dp[2][i + 1] + a[2][i];
    for (i = m - 1; i; i--) dp[1][i] = max(dp[1][i + 1], dp[2][i]) + a[1][i];
    for (i = 1; i <= m; i++)
      if (dp[2][1] > dp[1][i + 1]) {
        p = i;
        break;
      }
    for (i = 1; i <= p; i++) a[1][i] = 0;
    for (i = p; i <= m; i++) a[2][i] = 0;
    for (i = 1; i <= 2; i++)
      for (j = 1; j <= m; j++) dp[i][j] = 0;
    dp[2][m] = a[2][m];
    dp[1][m] = dp[2][m] + a[1][m];
    for (i = m - 1; i; i--) dp[2][i] = dp[2][i + 1] + a[2][i];
    for (i = m - 1; i; i--) dp[1][i] = max(dp[1][i + 1], dp[2][i]) + a[1][i];
    cout << dp[1][1] << endl;
  }
  return 0;
}
