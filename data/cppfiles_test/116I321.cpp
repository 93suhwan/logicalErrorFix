#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7, mod = 998244353;
long long f[N], a[N], Sum[N], res[N], dp[N][2];
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a, res %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n; i++)
      f[i] = 0, Sum[i] = 0, res[i] = 0, dp[i][0] = dp[i][1] = 0;
    long long cnt = 0, sum = 0;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = n; i >= 1; i--) Sum[a[i]]++;
    for (long long i = 1; i <= n; i++) {
      res[a[i]]++;
      if (a[i] == 0)
        cnt++, dp[a[i]][0]++;
      else if (a[i] == 1)
        dp[a[i]][0] += dp[a[i] - 1][0] + dp[a[i]][0],
            dp[a[i]][1] += dp[a[i]][1] + 1, dp[a[i]][0] %= mod,
            dp[a[i]][1] %= mod;
      else
        dp[a[i]][0] += dp[a[i] - 1][0] + dp[a[i]][0],
            dp[a[i]][1] += dp[a[i] - 2][0], dp[a[i]][0] %= mod,
            dp[a[i]][1] %= mod;
    }
    for (long long i = 1; i <= n; i++) sum += dp[i][0] + dp[i][1], sum %= mod;
    cout << (sum + qmi(2, cnt) - 1 + mod) % mod << endl;
  }
  return 0;
}
