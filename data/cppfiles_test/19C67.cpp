#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 4;
const int MAXL = 1e3 + 3;
const int inf = 0x3f3f3f3f;
int dp[MAXN][MAXL << 1], a[MAXN], n, t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    int lmx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      lmx = max(lmx, a[i]);
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 2 * lmx; j++) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2 * lmx; j++) {
        dp[i + 1][max(0, j - a[i + 1])] =
            min(dp[i + 1][max(0, j - a[i + 1])], dp[i][j] + a[i + 1]);
        if (j + a[i + 1] <= 2 * lmx)
          dp[i + 1][j + a[i + 1]] =
              min(dp[i + 1][j + a[i + 1]], max(0, dp[i][j] - a[i + 1]));
      }
    }
    int ans = inf;
    for (int i = 0; i <= 2 * lmx; i++) {
      ans = min(ans, dp[n][i] + i);
    }
    cout << ans << '\n';
  }
  return 0;
}
