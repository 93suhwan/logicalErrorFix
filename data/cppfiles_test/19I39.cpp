#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 1e4 + 5;
int t, n, a[2005];
int dp[MAXN][2005];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    int maxl = 0;
    for (int i = 0; i < n; i++) cin >> a[i], maxl = max(maxl, a[i]);
    vector<vector<int>> dp(n + 1, vector<int>(2 * maxl + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int left = 0; left <= 2 * maxl; left++) {
        if (dp[i][left] == INF) continue;
        dp[i + 1][max(left - a[i], 0)] =
            min(dp[i + 1][max(left - a[i], 0)], dp[i][left] + a[i]);
        if (left + a[i] < dp[i + 1].size()) {
          dp[i + 1][left + a[i]] =
              min(dp[i + 1][left + a[i]], max(dp[i][left] - a[i], 0));
        }
      }
    }
    int ans = INF;
    for (int i = 0; i <= 2 * maxl; i++) ans = min(dp[n][i] + i, ans);
    cout << ans << "\n";
  }
  return 0;
}
