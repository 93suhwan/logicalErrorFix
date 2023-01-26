#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, ans = 0;
    cin >> n;
    long long a[n], sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      a[i] = sum;
    }
    long long dp[n + 1][450];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) dp[i][0] = INT64_MAX;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 1; j <= min(n - i, 449); ++j) {
        dp[i][j] = dp[i + 1][j];
        long long seg = a[i + j - 1] - (i ? a[i - 1] : 0);
        if (seg < dp[i + j][j - 1]) dp[i][j] = max(dp[i][j], seg);
      }
    }
    for (int i = 1; i < 450; ++i)
      if (dp[0][i] != -1) ans = max(ans, i);
    cout << ans << '\n';
  }
}
