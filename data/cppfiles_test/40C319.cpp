#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, m, i, j;
  cin >> t;
  while (t--) {
    cin >> m;
    vector<vector<long long>> a(2, vector<long long>(m));
    for (i = 0; i < 2; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<long long>> dp(2, vector<long long>(m, 0));
    dp[1][0] = a[1][0];
    for (i = 0; i < 2; i++) {
      for (j = 1; j < m; j++) {
        if (i == 0 && j == 1) {
          dp[i][j] = a[i][j];
        } else if (i == 1 && j == 1) {
          dp[i][j] = a[i][j - 1] + a[i][j];
        } else {
          dp[i][j] = a[i][j] + dp[i][j - 1];
        }
      }
    }
    vector<long long> answer(m);
    for (i = 0; i < m; i++) {
      if (i == 0) {
        answer[i] = dp[0][m - 1];
      } else if (i == m - 1) {
        answer[i] = dp[1][m - 2];
      } else {
        answer[i] = max(dp[0][m - 1] - dp[0][i], dp[1][i - 1]);
      }
    }
    long long ans = answer[0];
    for (i = 1; i < m; i++) {
      ans = min(ans, answer[i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
