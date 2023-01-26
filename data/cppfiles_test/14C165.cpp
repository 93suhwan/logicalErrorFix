#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n + 2];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int dp[n + 2][n + 2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 0;
    if (a[0] == 1)
      dp[1][1] = 1;
    else
      dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if ((i) - (i - 1 - j) == (a[i - 1])) {
          if (dp[i - 1][j + 1] > (dp[i - 1][j] + 1)) {
            dp[i][j + 1] = dp[i - 1][j + 1];
          } else {
            dp[i][j + 1] = dp[i - 1][j] + 1;
          }
        } else {
          if (dp[i - 1][j + 1] > dp[i - 1][j]) {
            dp[i][j + 1] = dp[i - 1][j + 1];
          } else {
            dp[i][j + 1] = dp[i - 1][j];
          }
        }
      }
    }
    int k2 = 0;
    int ind = 0;
    for (int i = n; i >= 0; i--) {
      if (dp[n][i] >= k) {
        ind = i;
        k2 = 1;
        break;
      }
    }
    if (k2 != 0) {
      cout << (n - ind) << endl;
    } else
      cout << -1 << endl;
  }
}
