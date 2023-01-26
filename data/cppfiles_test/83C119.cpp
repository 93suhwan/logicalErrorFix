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
    string s;
    cin >> s;
    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = n - 2; i >= 0; i--) {
      d[i][n - 1] = (s[n - 1] > s[i]);
      for (int j = n - 2; j > i; j--) {
        if (s[j] < s[i])
          d[i][j] = 0;
        else if (s[j] > s[i])
          d[i][j] = n - j;
        else
          d[i][j] = d[i + 1][j + 1];
      }
    }
    vector<int> dp(n);
    dp[0] = n;
    for (int i = 1; i < n; i++) {
      dp[i] = n - i;
      for (int j = 0; j < i; j++) {
        if (d[j][i] > 0) dp[i] = max(dp[i], dp[j] + d[j][i]);
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    cout << res << '\n';
  }
  return 0;
}
