#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + (a[i] == i);
      for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j] + (a[i] == i - j), dp[i - 1][j - 1]);
      }
    }
    int ans = n + 1;
    for (int j = 0; j <= n; j++) {
      if (dp[n][j] >= k) ans = min(ans, j);
    }
    cout << (ans == n + 1 ? -1 : ans) << endl;
  }
}
