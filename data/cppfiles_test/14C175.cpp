#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[i - 1][j] + (x == i - j);
        if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    int res = -1;
    for (int i = 0; i <= n; i++)
      if (dp[n][i] >= k) {
        res = i;
        break;
      }
    cout << res << "\n";
  }
}
