#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    vector<vector<int>> dp(n, vector<int>(2, (int)1e9)),
        elozo(n, vector<int>(2, 0));
    dp[0] = {-(int)1e9, -(int)1e9};
    for (int i = 1; i < n; i++) {
      dp[i][0] = dp[i - 1][1];
      if (v[i] > dp[i - 1][1]) dp[i][0] = min(dp[i][0], -v[i - 1]);
      elozo[i][0] = 1;
      if (v[i] > dp[i - 1][0] && dp[i][0] > v[i - 1]) {
        dp[i][0] = v[i - 1];
        elozo[i][0] = 0;
      }
      if (v[i] > v[i - 1] && dp[i][0] > dp[i - 1][0]) {
        dp[i][0] = dp[i - 1][0];
        elozo[i][0] = 0;
      }
      if (-v[i] > dp[i - 1][0] && dp[i][1] > v[i - 1]) {
        dp[i][1] = v[i - 1];
        elozo[i][1] = 0;
      }
      if (-v[i] > dp[i - 1][1] && dp[i][1] > -v[i - 1]) {
        dp[i][1] = -v[i - 1];
        elozo[i][1] = 1;
      }
      if (-v[i] > -v[i - 1] && dp[i][1] > dp[i - 1][1]) {
        dp[i][1] = dp[i - 1][1];
        elozo[i][1] = 1;
      }
    }
    if (dp[n - 1][0] == (int)1e9) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (x) v[i] = -v[i];
      x = elozo[i][x];
    }
    for (int &x : v) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
