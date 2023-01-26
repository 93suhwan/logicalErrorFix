#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int t;
int n;
long long dp[500010][2];
long long x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      dp[i][0] = 0;
      dp[i][1] = 0;
    }
    dp[0][0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      x++;
      dp[x][0] = (dp[x][0] + dp[x][0]) % mod;
      dp[x][0] = (dp[x][0] + dp[x - 1][0]) % mod;
      if (x > 1) {
        dp[x][1] = (dp[x][1] + dp[x - 2][0]) % mod;
      }
    }
    for (int i = 1; i <= n + 1; i++) {
      ans = (ans + dp[i][0]) % mod;
      ans = (ans + dp[i][1]) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
