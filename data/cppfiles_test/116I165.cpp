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
    set<long long> s;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[i] = x;
      s.insert(x);
    }
    long long ans = 0;
    long long flag = 0, flag2 = 0;
    for (long long i = 0; i < n; i++) {
      if (flag == 1 && a[i] == 0) {
        dp[0][1] = ((2 * dp[0][1]) % MOD) + 1LL;
        dp[0][1] = dp[0][1] % MOD;
        dp[0][0] = dp[0][1] % MOD;
      } else if (a[i] == 0 && flag == 0) {
        flag = 1;
        dp[0][1] = 1;
        dp[0][0] = 1;
      } else {
        if (a[i] - 2 >= 0) {
          dp[a[i]][0] = ((2 * dp[a[i]][0]) % MOD + dp[a[i] - 2][1]) % MOD;
          dp[a[i]][0] = (dp[a[i]][0]) % MOD;
        }
        if (a[i] - 1 >= 0) {
          dp[a[i]][1] = ((2 * dp[a[i]][1]) % MOD + dp[a[i] - 1][1]) % MOD;
          dp[a[i]][1] = (dp[a[i]][1]) % MOD;
          if (flag2 == 1 && a[i] == 1) {
            dp[1][0] = ((2 * dp[1][0]) % MOD) + 1LL;
            dp[1][0] = dp[1][0] % MOD;
          }
          if (flag2 == 0 && a[i] == 1) {
            dp[1][0] = 1;
            flag2 = 1;
          }
        }
      }
    }
    for (auto &i : s) {
      if (i == 0) {
        long long cnt = dp[0][1] % MOD;
        ans = (ans + cnt) % MOD;
        ans = (ans) % MOD;
      } else {
        ans = (ans + dp[i][0]) % MOD;
        ans = (ans) % MOD;
        ans = (ans + dp[i][1]) % MOD;
        ans = (ans) % MOD;
      }
    }
    cout << ans << "\n";
  }
}
