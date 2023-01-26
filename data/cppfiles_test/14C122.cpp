#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[2010];
int dp[2010][2010];
int main() {
  cin >> t;
  while (t--) {
    int ans = 0x3f3f3f3f;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (j == a[i]));
        if (dp[i][j] >= k) ans = min(ans, i - j);
      }
    if (ans == 0x3f3f3f3f)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
