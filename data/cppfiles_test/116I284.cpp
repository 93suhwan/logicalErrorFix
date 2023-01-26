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
    vector<vector<long long>> dp(n + 6, vector<long long>(2, 0));
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[i] = x;
      s.insert(x);
    }
    dp[0][0] = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      if ((a[i] == 0)) {
        dp[1][0] = ((2 * dp[1][0]) % MOD + (dp[1][1]) % MOD) % MOD + 1LL;
        dp[1][0] = dp[1][0] % MOD;
      } else if (a[i] == 1) {
        dp[0][1] = (2 * dp[0][1]) % MOD + 1LL;
        dp[0][1] = dp[0][1] % MOD;
        dp[2][0] = ((2 * dp[2][0]) % MOD + (dp[2][1]) % MOD) % MOD;
        dp[2][0] = (dp[2][0]) % MOD;
      } else {
        dp[a[i] - 1][1] =
            ((2 * dp[a[i] - 1][1]) % MOD + (dp[a[i] - 1][0]) % MOD) % MOD;
        dp[a[i] + 1][0] =
            ((2 * dp[a[i] + 1][0]) % MOD + (dp[a[i] + 1][1]) % MOD) % MOD;
      }
    }
    for (auto &i : s) {
      auto val = i;
      if (val - 1 >= 0) {
        ans = (ans + dp[val - 1][1]) % MOD;
      }
      ans = (ans) % MOD;
      ans = (ans + dp[val + 1][0]) % MOD;
      ans = (ans) % MOD;
    }
    cout << ans << "\n";
  }
}
