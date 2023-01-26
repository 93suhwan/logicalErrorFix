#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++)
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (j == arr[i]));
    dp[i][i] = dp[i - 1][i - 1] + (i == arr[i]);
  }
  for (int i = n; i >= 0; i--)
    if (dp[n][i] >= k) {
      cout << n - i << '\n';
      return;
    }
  cout << "-1" << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
