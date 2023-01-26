#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[2005], dp[2005][2005];
int main() {
  cin >> t;
  while (t--) {
    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] <= i) ans++;
    }
    if (ans < k) {
      cout << -1 << endl;
      continue;
    }
    ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (i - a[i] == j) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        } else {
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
      }
      cout << endl;
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[n][i] >= k) {
        cout << i << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) cout << -1 << endl;
  }
  return 0;
}
