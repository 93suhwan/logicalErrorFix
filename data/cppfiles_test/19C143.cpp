#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  for (int _i = 0; _i < t; _i++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sz = 3e3 + 1000;
    vector<vector<int> > dp(n + 1, vector<int>(sz, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < dp[i].size(); j++) {
        if (j <= a[i]) {
          dp[i + 1][0] = min(dp[i + 1][0], abs(j - a[i]) + dp[i][j]);
        } else {
          dp[i + 1][j - a[i]] = min(dp[i + 1][j - a[i]], dp[i][j]);
        }
        if (j + a[i] < dp[i + 1].size()) {
          dp[i + 1][j + a[i]] =
              min(dp[i + 1][j + a[i]], max(dp[i][j], j + a[i]));
        }
      }
    }
    int ans = 1e9;
    for (int i = 0; i < dp[n].size(); i++) {
      ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
  }
}
