#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int a[MAXN];
int dp[MAXN][2005];
int solve(int n) {
  int len = 2005;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < len; ++j) dp[i][j] = INT_MAX;
  for (int j = 0; j < len; ++j) dp[0][j] = j;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < len; ++j) {
      if (j >= a[i]) dp[i][j - a[i]] = min(dp[i][j - a[i]], dp[i - 1][j]);
      if (j + a[i] < len)
        dp[i][j + a[i]] = min(dp[i][j + a[i]], max(dp[i - 1][j], j + a[i]));
    }
  }
  int ans = INT_MAX;
  for (int j = 0; j < len; ++j) ans = min(ans, dp[n][j]);
  return ans;
}
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << solve(n) << endl;
  }
  return 0;
}
