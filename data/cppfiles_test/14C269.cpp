#include <bits/stdc++.h>
using namespace std;
int dp[2100][2100];
void solve() {
  int n, m, k, a[2100];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    dp[i][0] = (a[i] == 1);
    for (int j = 1; j < i; j++) {
      dp[i][j] = max(dp[i - 1][j] - (a[i - 1] == j + 1), dp[i - 1][j - 1]) +
                 (a[i] == j + 1);
    }
    if (i > 0) dp[i][i] = dp[i - 1][i - 1] + (a[i] == i + 1);
  }
  int ans = 2e9;
  for (int j = n - 1; j >= 0; j--)
    for (int i = n - 1; i >= j; i--)
      if (dp[i][j] >= k) ans = min(ans, n - j - 1);
  if (ans == 2e9)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
