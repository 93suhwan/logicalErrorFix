#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    for (int j = i; j >= 1; j--) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      dp[i][j] =
          max(dp[i][j], arr[i] == j ? 1 + dp[i - 1][j - 1] : dp[i - 1][j - 1]);
    }
  }
  for (int j = n; j >= 0; j--) {
    if (dp[n][j] >= k) {
      cout << n - j << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
