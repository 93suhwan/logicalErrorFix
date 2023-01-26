#include <bits/stdc++.h>
using namespace std;
long long maxn = 200000 + 2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 2005;
    for (int i = 1; i <= n; i++) {
      if (arr[i - 1] == i)
        dp[i][0] = dp[i - 1][0] + 1;
      else
        dp[i][0] = dp[i - 1][0];
      for (int j = 1; j <= i; j++) {
        if ((i - j) == arr[i - 1])
          dp[i][j] = dp[i - 1][j] + 1;
        else
          dp[i][j] = dp[i - 1][j];
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        if (dp[i][j] == k) ans = min(ans, j);
      }
    }
    if (ans == 2005)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
