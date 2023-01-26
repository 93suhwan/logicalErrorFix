#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod = 998244353;
const double PI = 3.14159265359;
const double eps = 1e-9;
int n, v[500002], dp[2][500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (; t; --t) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    int ans = 0;
    dp[1][0] = 1;
    for (int i = 1; i <= n; ++i) {
      dp[1][v[i] + 1] += dp[1][v[i] + 1];
      if (dp[1][v[i] + 1] >= mod) dp[1][v[i] + 1] -= mod;
      dp[1][v[i] + 1] += dp[1][v[i]];
      if (dp[1][v[i] + 1] >= mod) dp[1][v[i] + 1] -= mod;
      if (v[i] > 0) {
        dp[0][v[i] - 1] += dp[0][v[i] - 1];
        if (dp[0][v[i] - 1] >= mod) dp[0][v[i] - 1] -= mod;
        dp[0][v[i] - 1] += dp[1][v[i] - 1];
        if (dp[0][v[i] - 1] >= mod) dp[0][v[i] - 1] -= mod;
      }
      dp[0][v[i] + 1] += dp[0][v[i] + 1];
      if (dp[0][v[i] + 1] >= mod) dp[0][v[i] + 1] -= mod;
    }
    for (int i = 0; i <= n + 2; ++i) {
      ans = ans + dp[0][i];
      ans = ans + dp[1][i];
      while (ans >= mod) ans -= mod;
      dp[0][i] = dp[1][i] = 0;
    }
    cout << (ans + mod - 1) % mod << '\n';
  }
  return 0;
}
