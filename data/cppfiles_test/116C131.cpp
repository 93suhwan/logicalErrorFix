#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7, mod = 998244353;
long long a[N], dp[N][2];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n + 5; i++) dp[i][0] = dp[i][1] = 0;
    dp[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      (dp[x + 1][0] += dp[x + 1][0]) %= mod;
      (dp[x + 1][1] += dp[x + 1][1]) %= mod;
      (dp[x + 1][0] += dp[x][0]) %= mod;
      if (x)
        (dp[x - 1][1] += dp[x - 1][1]) %= mod,
            (dp[x - 1][1] += dp[x - 1][0]) %= mod;
    }
    long long sum = -1;
    for (long long i = 0; i <= n; i++) sum += dp[i][0] + dp[i][1], sum %= mod;
    cout << sum << endl;
  }
  return 0;
}
