#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1;
  cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int &i : arr) cin >> i;
    vector<vector<long long int>> dp(n + 5, vector<long long int>(3));
    for (int i = 0; i < n; i++) {
      long long int k = arr[i];
      if (k == 0) {
        dp[k][0] += dp[k][0] + 1;
        continue;
      }
      if (k == 1) {
        dp[k][0] = (dp[k][0] + dp[k][0]) % mod;
        dp[k][0] = (dp[k][0] + dp[k - 1][0]) % mod;
        dp[k][1] = (dp[k][1] + dp[k][1] + 1) % mod;
        dp[k][2] = (dp[k][2] + dp[k][2]) % mod;
        dp[k][2] = (dp[k][2] + dp[k + 2][1]) % mod;
        continue;
      }
      dp[k][0] = (dp[k][0] + dp[k][0]) % mod;
      dp[k][0] = (dp[k][0] + dp[k - 1][0]) % mod;
      dp[k][1] = (dp[k][1] + dp[k][1]) % mod;
      dp[k][1] = (dp[k][1] + dp[k - 2][0]) % mod;
      dp[k][1] = (dp[k][1] + dp[k - 2][2]) % mod;
      dp[k][2] = (dp[k][2] + dp[k][2]) % mod;
      dp[k][2] = (dp[k][2] + dp[k + 2][1]) % mod;
    }
    long long int res = 0;
    for (auto &i : dp) {
      res = (res + i[0] + i[1] + i[2]) % mod;
    }
    cout << res;
    if (TC) cout << '\n';
  }
  return 0;
}
