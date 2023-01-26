#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 1e9;
int dp[2][2005], a[10005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(dp, 0x3f, sizeof dp);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int now = 0;
    dp[0][a[1]] = 0;
    dp[0][0] = a[1];
    for (int i = 2; i <= n; now ^= 1, i++) {
      memset(dp[1 - now], 0x3f, sizeof dp[1 - now]);
      for (int j = 0; j <= 2000; j++) {
        if (j + a[i] <= 2000)
          dp[1 - now][j + a[i]] =
              min(dp[1 - now][j + a[i]], max(0, dp[now][j] - a[i]));
        dp[1 - now][max(j - a[i], 0)] =
            min(dp[1 - now][max(j - a[i], 0)], dp[now][j] + a[i]);
      }
    }
    int ans = 2000000;
    for (int j = 0; j <= 2000; j++) {
      ans = min(ans, j + dp[now][j]);
    }
    cout << ans << endl;
  }
  return 0;
}
