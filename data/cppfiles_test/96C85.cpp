#include <bits/stdc++.h>
using namespace std;
const bool MULTITEST = 0;
const long long MOD = 998244353;
long long bpow(long long base, long long power) {
  if (power == 0) return 1;
  long long ret = bpow(base, power / 2);
  ret = (ret * ret) % MOD;
  if (power % 2 == 1) ret = (ret * base) % MOD;
  return ret;
}
long long solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
  for (long long i = 0; i <= n; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
  dp[n][0] = 1;
  for (long long i = n; i >= 2; i--) {
    for (long long j = 0; j <= k; j++) {
      if (dp[i][j] == 0) continue;
      long long pw = 1, nj = min(k, j + i - 1);
      for (long long ni = i; ni >= 0; ni--) {
        dp[ni][nj] =
            (dp[ni][nj] + ((dp[i][j] * ((c[i][i - ni] * pw) % MOD)) % MOD)) %
            MOD;
        pw = (pw * (nj - j)) % MOD;
      }
    }
  }
  long long sum = 0;
  for (long long j = 0; j <= k; j++) {
    sum += dp[0][j];
    sum %= MOD;
  }
  cout << sum;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  if (MULTITEST) cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
