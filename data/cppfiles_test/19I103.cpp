#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N], t, n, x, ans, a[N];
void init(int idx) {
  for (int j = 0; j <= 2000; j++) {
    dp[idx][j] = 1e9;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    init(0);
    dp[0][0] = 0;
    ans = 1e9;
    for (int i = 1; i <= n; i++) {
      init(i);
      for (int j = 0; j <= 2000; j++) {
        x = dp[i - 1][j];
        dp[i][max(0, j - a[i])] =
            min(dp[i][max(0, j - a[i])], x + max(0, a[i] - j));
        x = dp[i - 1][j];
        dp[i][j + a[i]] = min(dp[i][j + a[i]], max(x, j + a[i]));
      }
    }
    for (int j = 0; j <= 2000; j++) {
      ans = min(ans, dp[n][j]);
    }
    cout << ans << "\n";
  }
}
