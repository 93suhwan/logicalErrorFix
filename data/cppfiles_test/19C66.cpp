#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int& e : a) cin >> e;
    int c = 2005;
    vector<vector<int>> dp(n + 1, vector<int>(c, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < c; j++) {
        dp[i + 1][max(j - a[i], 0)] =
            min(dp[i + 1][max(j - a[i], 0)], dp[i][j] + a[i]);
        if (j + a[i] < c)
          dp[i + 1][j + a[i]] =
              min(dp[i + 1][j + a[i]], max(dp[i][j] - a[i], 0));
      }
    }
    int ans = 1e9;
    for (int i = 0; i < c; i++) ans = min(ans, i + dp[n][i]);
    cout << ans << '\n';
  }
}
