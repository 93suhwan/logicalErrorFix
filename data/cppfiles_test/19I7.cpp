#include <bits/stdc++.h>
using namespace std;
int dp[10010][2010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int T = (0); T < (t); T++) {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = (0); i < (n); i++) cin >> l[i];
    for (int i = (0); i < (n + 1); i++)
      for (int j = (0); j < (2010); j++) dp[i][j] = INT_MAX;
    dp[0][0] = 0;
    for (int i = (0); i < (n); i++) {
      for (int j = (0); j < (2001); j++) {
        if (dp[i][j] == INT_MAX) continue;
        dp[i + 1][max(0, j - l[i])] =
            min(dp[i + 1][max(0, j - l[i])], dp[i][j] + l[i]);
        dp[i + 1][j + l[i]] = min(dp[i + 1][j + l[i]], max(dp[i][j] - l[i], 0));
      }
    }
    int ans = INT_MAX;
    for (int i = (0); i < (2001); i++)
      if (dp[n][i] != INT_MAX) ans = min(ans, dp[n][i] + i);
    cout << ans << "\n";
  }
  return 0;
}
