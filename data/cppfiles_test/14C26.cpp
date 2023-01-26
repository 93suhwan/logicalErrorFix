#include <bits/stdc++.h>
const long double eps = 1e-8;
const long long int dx[4] = {-1, 0, 1, 0};
const long long int dy[4] = {0, 1, 0, -1};
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> v(n);
    for (auto &i : v) cin >> i;
    long long int dp[n + 1][n + 1];
    dp[0][0] = 0;
    for (long long int i = 1; i <= n; i++) {
      dp[0][i] = -1e16;
    }
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = 0; j <= n; j++) {
        dp[i][j] = -1e16;
        if (v[i - 1] == (i - j))
          dp[i][j] = dp[i - 1][j] + 1;
        else
          dp[i][j] = dp[i - 1][j];
        if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    long long int ans = -1;
    for (long long int i = 0; i < n; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
}
