#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n + 6, vector<int>(2, 0));
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = x;
      s.insert(x);
    }
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if ((a[i] == 0)) {
        dp[1][0] = (2 * dp[1][0] + dp[1][1]) % MOD + 1LL;
        dp[1][0] = dp[1][0] % MOD;
      } else if (a[i] == 1) {
        dp[0][1] = (2 * dp[0][1]) % MOD + 1LL;
        dp[0][1] = dp[0][1] % MOD;
        dp[2][0] = (2 * dp[2][0] + dp[2][1] + dp[1][0]) % MOD;
        dp[2][0] = (dp[2][0]) % MOD;
      } else {
        dp[a[i] - 1][1] = (2 * dp[a[i] - 1][1] + dp[a[i] - 1][0]) % MOD;
        dp[a[i] + 1][0] =
            (2 * dp[a[i] + 1][0] + dp[a[i] + 1][1] + dp[a[i]][0]) % MOD;
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
