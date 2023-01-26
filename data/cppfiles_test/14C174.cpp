#include <bits/stdc++.h>
using namespace std;
int64_t solve(int64_t i, int64_t j, vector<vector<int64_t>>& dp,
              vector<int64_t>& v) {
  if (dp[i][j] != -1) return dp[i][j];
  if (j > i) return -1e9;
  if (i == 0) return dp[i][j] = 0;
  if (j == 0) {
    if (v[i] == i) return dp[i][j] = solve(i - 1, j, dp, v) + 1;
    return dp[i][j] = solve(i - 1, j, dp, v);
  }
  dp[i][j] = max(solve(i - 1, j - 1, dp, v), dp[i][j]);
  if (v[i] == i - j)
    dp[i][j] = max(solve(i - 1, j, dp, v) + 1, dp[i][j]);
  else
    dp[i][j] = max(solve(i - 1, j, dp, v), dp[i][j]);
  return dp[i][j];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t T;
  cin >> T;
  for (int64_t t = 0; t < T; ++t) {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> v(n + 1);
    for (int64_t i = 1; i <= n; ++i) {
      int64_t a;
      cin >> a;
      v[i] = a;
    }
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(n + 1, -1));
    vector<int64_t> fred(n + 1);
    for (int64_t i = 0; i <= n; ++i) {
      fred[i] = solve(n, i, dp, v);
    }
    int64_t ans = 1e9;
    for (int64_t i = 0; i <= n; ++i) {
      if (fred[i] >= k) ans = min(ans, i);
    }
    if (ans == 1e9)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
}
