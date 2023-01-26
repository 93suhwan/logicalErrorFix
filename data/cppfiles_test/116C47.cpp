#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
int mx = 1e7 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    long long int dp[n + 2][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (a[i] - 1 >= 0) {
        dp[a[i] - 1][1] *= 2;
        dp[a[i] - 1][1] %= mod;
        dp[a[i] - 1][1] += dp[a[i] - 1][0], dp[a[i] - 1][1] %= mod;
      }
      dp[a[i] + 1][0] *= 2, dp[a[i] + 1][0] %= mod;
      dp[a[i] + 1][1] *= 2, dp[a[i] + 1][1] %= mod;
      dp[a[i] + 1][0] += dp[a[i]][0], dp[a[i] + 1][0] %= mod;
      if (a[i] == 1) dp[0][1]++, dp[0][1] %= mod;
      if (a[i] == 0) dp[1][0]++, dp[1][0] %= mod;
    }
    long long int ans = 0;
    for (int i = 0; i <= n + 1; i++) {
      ans += dp[i][0] + dp[i][1], ans %= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
