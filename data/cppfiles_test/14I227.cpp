#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int w;
  cin >> w;
L:
  while (w--) {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (long long int i = 0; i < n; i++) {
      cin >> A[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    if (A[0] == 1) {
      dp[0][0] = 1;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (A[i] == i + 1 - j) {
          if (dp[i - 1][j] != -1) {
            dp[i][j] = dp[i - 1][j] + 1;
            if (j && dp[i - 1][j - 1] != -1) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
          } else {
            dp[i][j] = 1;
            if (j && dp[i - 1][j - 1] != -1) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
          }
        } else {
          if (j && dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j];
          if (dp[i - 1][j - 1] != -1) {
            if (dp[i][j] != -1) {
              dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            } else {
              dp[i][j] = dp[i - 1][j - 1];
            }
          }
        }
      }
    }
    int ans = 10001;
    for (int i = 0; i < n; i++) {
      if (dp[n - 1][i] != -1 && dp[n - 1][i] >= k) {
        ans = i;
        break;
      }
    }
    if (ans == 10001) {
      cout << "-1\n";
    } else {
      cout << ans << endl;
    }
  }
  return (0);
}
