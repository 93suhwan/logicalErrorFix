#include <bits/stdc++.h>
using LL = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  ;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 0; i < n; ++i) cin >> a[i + 1];
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    ;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i][j + 1] = dp[i - 1][j];
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + ((i - j) == a[i]));
      }
    }
    int res = -1;
    for (int i = 0; i <= n; ++i)
      if (dp[n][i] >= k) {
        res = i;
        break;
      }
    cout << res << '\n';
  }
}
