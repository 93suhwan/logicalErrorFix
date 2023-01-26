#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3 + 1;
int a[N], dp[N][N][3];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    for (int l = 2; l <= n; ++l)
      for (int i = 0; i + l <= n; ++i) {
        int t = min(
            {min(dp[i][l - 1][0], dp[i + 1][l - 1][1]) + (a[i + l - 1] != a[i]),
             dp[i][l - 1][2] + 1, dp[i + 1][l - 1][2] + 1,
             dp[i + 1][l - 2][2] + 1 + (a[i + l - 1] != a[i])});
        dp[i][l][0] = min(t, dp[i + 1][l - 1][0] + (a[i] != a[i + 1]));
        dp[i][l][1] = min(t, dp[i][l - 1][1] + (a[i + l - 1] != a[i + l - 2]));
        dp[i][l][2] = min({dp[i][l][0], dp[i][l][1]});
      }
    cout << dp[0][n][2] << '\n';
    ;
  }
  return 0;
}
