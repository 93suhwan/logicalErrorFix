#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, i, m, ans = 1e18, j;
  cin >> n >> k;
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  for (i = 0; i < n; i++) {
    cin >> m;
    for (j = 0; j <= i; j++) {
      dp[i + 1][j] = fmax(dp[i + 1][j], dp[i][j]);
      if (m == j + 1) {
        dp[i + 1][j + 1] = fmax(dp[i + 1][j + 1], dp[i][j] + 1);
      } else {
        dp[i + 1][j + 1] = fmax(dp[i + 1][j + 1], dp[i][j]);
      }
    }
  }
  for (i = k; i <= n; i++) {
    if (dp[n][i] >= k) {
      ans = fmin(ans, n - i);
    }
  }
  if (ans == 1e18) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
