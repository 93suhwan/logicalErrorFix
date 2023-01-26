#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (a[i + 1] == j + 1));
    }
  for (int i = n; i >= 0; i--)
    if (dp[n][i] >= k) {
      cout << n - i << '\n';
      return;
    }
  cout << "-1\n";
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
