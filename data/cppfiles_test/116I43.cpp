#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long add(long long a, long long b) { return (a + b) % mod; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(7);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<long long>> dp(n + 5, {0, 0});
    for (long long i = 0; i < n; i++) {
      if (a[i] == 0) {
        dp[a[i] + 1][0] = add(add(dp[a[i] + 1][0], 1), dp[a[i] + 1][0]);
        dp[a[i] + 1][1] = add(dp[a[i] + 1][1], dp[a[i] + 1][1]);
      } else {
        if (a[i] == 1) {
          dp[a[i] - 1][1] = add(dp[a[i] - 1][1], dp[a[i] - 1][1] + 1);
          dp[a[i] + 1][0] = add(dp[a[i] + 1][0], dp[a[i]][0]);
          dp[a[i] + 1][1] = add(dp[a[i] + 1][1], dp[a[i] + 1][1]);
        } else {
          dp[a[i] + 1][0] = add(dp[a[i] + 1][0], dp[a[i]][0]);
          dp[a[i] - 1][1] =
              add(add(dp[a[i] - 1][1], dp[a[i] - 1][1]), dp[a[i] - 1][0]);
          dp[a[i] + 1][1] = add(dp[a[i] + 1][1], dp[a[i] + 1][1]);
        }
      }
    }
    long long res = 0;
    for (long long i = 0; i < n + 5; i++) {
      res = add(add(res, dp[i][0]), dp[i][1]);
    }
    cout << res << "\n";
  }
}
