#include <bits/stdc++.h>
using namespace std;
const long long N = 4000009;
long long MOD;
long long dp[N];
signed main(void) {
  ios::sync_with_stdio(false);
  long long n;
  cin >> n >> MOD;
  dp[1] = 1;
  dp[2] = 2;
  for (long long j = 4; j < N; j += 2) dp[j] += dp[2] - dp[1];
  for (long long i = 3; i <= n; i++) {
    dp[i] += 2 * dp[i - 1] + dp[1];
    dp[i] %= MOD;
    for (long long j = 2 * i; j < N; j += i) dp[j] += dp[i] - dp[i - 1];
  }
  cout << (dp[n] % MOD + MOD) % MOD << endl;
  return 0;
}
