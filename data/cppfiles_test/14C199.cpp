#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> vec[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      if (i == vec[i])
        dp[i][0] = 1 + dp[i - 1][0];
      else
        dp[i][0] = dp[i - 1][0];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i][j] =
            max(dp[i - 1][j - 1], dp[i - 1][j] + (vec[i] == (i - j) ? 1 : 0));
      }
    }
    bool flag = false;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] >= k) {
        flag = true;
        ans = i;
        break;
      }
    }
    if (flag)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
