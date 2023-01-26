#include <bits/stdc++.h>
using namespace std;
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
        dp[k][0] = (dp[k][0] + dp[k][0] + 1) % 998244353;
        ;
        dp[k][2] = (dp[k][2] + dp[k][2]) % 998244353;
        ;
        dp[k][2] = (dp[k][2] + dp[k + 2][1]) % 998244353;
        ;
        continue;
      }
      if (k == 1) {
        dp[k][0] = (dp[k][0] + dp[k][0]) % 998244353;
        ;
        dp[k][0] = (dp[k][0] + dp[k - 1][0]) % 998244353;
        ;
        dp[k][1] = (dp[k][1] + dp[k][1] + 1) % 998244353;
        ;
        dp[k][2] = (dp[k][2] + dp[k][2]) % 998244353;
        ;
        dp[k][2] = (dp[k][2] + dp[k + 2][1]) % 998244353;
        ;
        continue;
      }
      dp[k][0] = (dp[k][0] + dp[k][0]) % 998244353;
      ;
      dp[k][0] = (dp[k][0] + dp[k - 1][0]) % 998244353;
      ;
      dp[k][1] = (dp[k][1] + dp[k][1]) % 998244353;
      ;
      dp[k][1] = (dp[k][1] + dp[k - 2][0]) % 998244353;
      ;
      dp[k][1] = (dp[k][1] + dp[k - 2][2]) % 998244353;
      ;
      dp[k][2] = (dp[k][2] + dp[k][2]) % 998244353;
      ;
      dp[k][2] = (dp[k][2] + dp[k + 2][1]) % 998244353;
      ;
    }
    long long int res = 0;
    for (auto &i : dp) {
      res = (res + i[0] + i[1] + i[2]) % 998244353;
      ;
    }
    cout << res;
    if (TC) cout << '\n';
  }
  return 0;
}
