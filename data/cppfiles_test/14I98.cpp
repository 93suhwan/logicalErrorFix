#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i][j] = max(dp[i - 1][j] + (v[i] == i - j), dp[i - 1][j - 1]);
      }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
