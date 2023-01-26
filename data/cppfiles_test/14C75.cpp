#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int ii = 0; ii < tt; ii++) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] =
            max(dp[i + 1][j + 1], dp[i][j] + ((v[i + 1] == j + 1) ? 1 : 0));
      }
    }
    int res = -1;
    for (int i = n; i >= 0; i--) {
      if (dp[n][i] >= k) {
        res = n - i;
        break;
      }
    }
    cout << res << endl;
  }
  return 0;
}
