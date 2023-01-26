#include <bits/stdc++.h>
using namespace std;
int T, case_;
int n, a;
int dp[2][20004], ans;
void solve() {
  ans = 0x3f3f3f3f;
  memset(dp[0], 63, sizeof(dp[0]));
  dp[0][0] = 0;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    memset(dp[1], 63, sizeof(dp[1]));
    cin >> a;
    for (int j = 0; j <= 10004 - 1; j++) {
      if (dp[0][j] == 0x3f3f3f3f) continue;
      if (a < j) {
        dp[1][j - a] = min(dp[1][j - a], dp[0][j]);
      } else {
        dp[1][0] = min(dp[1][0], dp[0][j] - j + a);
      }
      dp[1][j + a] = min(dp[1][j + a], max(j + a, dp[0][j]));
    }
    memcpy(dp[0], dp[1], sizeof(dp[0]));
  }
  for (int i = 0; i <= 10004 - 1; i++) ans = min(ans, dp[0][i]);
  cout << ans << endl;
}
int main() {
  T = 1;
  cin >> T;
  for (case_ = 1; case_ <= T; case_++) solve();
  return 0;
}
