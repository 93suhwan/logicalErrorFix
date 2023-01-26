#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<vector<long long>> dp(n + 4, vector<long long>(2, 0));
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[i] = x;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 0) {
        dp[0][0] = (dp[0][0] + 1LL) % MOD;
        dp[0][0] = dp[0][0] % MOD;
        dp[0][1] = (dp[0][1] + 1LL) % MOD;
        dp[0][1] = dp[0][1] % MOD;
      } else if (a[i] == 1) {
        dp[1][0] = (dp[1][0] + 1LL) % MOD;
        dp[1][0] = dp[1][0] % MOD;
      } else {
        if (a[i] - 2 >= 0) {
          dp[a[i]][0] = (dp[a[i]][0] + dp[a[i] - 2][1]) % MOD;
          dp[a[i]][0] = (dp[a[i]][0]) % MOD;
        }
        if (a[i] - 1 >= 0) {
          dp[a[i]][1] = (dp[a[i]][1] + dp[a[i] - 1][1]) % MOD;
          dp[a[i]][1] = (dp[a[i]][1]) % MOD;
        }
      }
      if (a[i] == 0) {
        ans = (ans + 1LL) % MOD;
        ans = (ans) % MOD;
      } else {
        ans = (ans + dp[a[i]][0]) % MOD;
        ans = (ans) % MOD;
        ans = (ans + dp[a[i]][1]) % MOD;
        ans = (ans) % MOD;
      }
    }
    cout << ans << "\n";
  }
}
