#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9;
long long dp[505][505];
long long c[505][505];
void solve() {
  long long nn, xx;
  cin >> nn >> xx;
  for (long long n = 0; n < 505; ++n) {
    for (long long k = 0; k <= n; ++k) {
      if (k && n > k) {
        c[n][k] = (c[n - 1][k] + c[n - 1][k - 1]) % MOD;
      } else {
        c[n][k] = 1;
      }
    }
  }
  for (long long n = 0; n <= nn; ++n) {
    for (long long x = 1; x <= xx; ++x) {
      if (n == 0) {
        dp[0][x] = 1;
        continue;
      }
      if (n == 1) {
        dp[1][x] = 0;
        continue;
      }
      if (x < n) {
        dp[n][x] = 1;
        for (long long i = 0; i < n; ++i) {
          dp[n][x] *= x;
          dp[n][x] %= MOD;
        }
        continue;
      }
      long long st = 1;
      for (long long i = 0; i <= n; ++i) {
        dp[n][x] += dp[n - i][x - n + 1] * st % MOD * c[n][i] % MOD;
        dp[n][x] %= MOD;
        st *= n - 1;
        st %= MOD;
      }
    }
  }
  cout << dp[nn][xx] << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
