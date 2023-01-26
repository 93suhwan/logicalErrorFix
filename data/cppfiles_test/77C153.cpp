#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 4e6 + 5;
long long n, m, dp[MAXN], f1[MAXN], f2[MAXN], s;
signed main() {
  cin >> n >> m;
  f2[1] = 1;
  f2[2] = m - 1;
  for (long long i = 1; i <= n; ++i) {
    (s += f2[i]) %= m;
    dp[i] = (f1[i - 1] + s) % m;
    for (long long j = 2; i * j <= n; ++j) {
      (f2[i * j] += dp[i]) %= m;
      if (i * j + j <= n) {
        (f2[i * j + j] -= dp[i]) %= m;
      }
    }
    f1[i] = (f1[i - 1] + dp[i]) % m;
  }
  dp[n] %= m;
  dp[n] = (dp[n] + m) % m;
  cout << dp[n] << endl;
  return 0;
}
