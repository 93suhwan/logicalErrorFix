#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
long long dp[70][6];
void solve() {
  int k;
  cin >> k;
  for (int i = 0; i < 6; i++) dp[1][i] = 1;
  for (int i = 2; i <= k; i++) {
    long long sum = 0;
    for (int y = 0; y < 6; y++) {
      sum += dp[i - 1][y];
      sum %= M;
    }
    dp[i][0] = (sum - dp[i - 1][0] - dp[i - 1][3]) *
               (sum - dp[i - 1][0] - dp[i - 1][3]);
    dp[i][0] += M;
    dp[i][0] %= M;
    dp[i][1] = (sum - dp[i - 1][1] - dp[i - 1][5]) *
               (sum - dp[i - 1][1] - dp[i - 1][5]);
    dp[i][1] += M;
    dp[i][1] %= M;
    dp[i][2] = (sum - dp[i - 1][2] - dp[i - 1][4]) *
               (sum - dp[i - 1][2] - dp[i - 1][4]);
    dp[i][2] += M;
    dp[i][2] %= M;
    dp[i][3] = (sum - dp[i - 1][0] - dp[i - 1][3]) *
               (sum - dp[i - 1][0] - dp[i - 1][3]);
    dp[i][3] += M;
    dp[i][3] %= M;
    dp[i][4] = (sum - dp[i - 1][2] - dp[i - 1][4]) *
               (sum - dp[i - 1][2] - dp[i - 1][4]);
    dp[i][4] += M;
    dp[i][4] %= M;
    dp[i][5] = (sum - dp[i - 1][1] - dp[i - 1][5]) *
               (sum - dp[i - 1][1] - dp[i - 1][5]);
    dp[i][5] += M;
    dp[i][5] %= M;
  }
  long long ans = 0;
  for (int i = 0; i < 6; i++) {
    ans += dp[k][i];
    ans %= M;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
