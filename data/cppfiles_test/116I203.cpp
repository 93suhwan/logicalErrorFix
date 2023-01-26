#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, mod = 998244353;
long long dp[M][2];
void solve() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(dp[0], 0, sizeof(long long) * (n + 10));
    memset(dp[1], 0, sizeof(long long) * (n + 10));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      x++;
      dp[x][0] += dp[x][0] + dp[x - 1][0];
      dp[x][1] *= 2;
      dp[x + 2][1] *= 2;
      if (x > 1) {
        dp[x][1] += dp[x - 2][0];
      }
      dp[x][0] %= mod;
      dp[x][1] %= mod;
      dp[x + 2][1] %= mod;
    }
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      ans = (ans + dp[i][0] + dp[i][1]) % mod;
    }
    cout << ans << "\n";
  }
}
int main() {
  cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
