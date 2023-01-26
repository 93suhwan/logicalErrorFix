#include <bits/stdc++.h>
using namespace std;
long long MOD;
long long MAXN = 1e5 + 1;
long long mod(long long a) { return ((a % MOD) + MOD) % MOD; }
long long add(long long x, long long y) { return mod(mod(x) + mod(y)); }
long long mul(long long x, long long y) { return mod(mod(x) * mod(y)); }
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long ans = power(x, y / 2);
  ans = mul(ans, ans);
  if (y % 2 == 1) {
    ans = mul(ans, x);
  }
  return ans;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1);
  long long sum = 1;
  dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = sum;
    for (long long j = 1; j * j <= i; j++) {
      dp[i] += (dp[j] * (i / j - i / (j + 1))) % m;
      dp[i] %= m;
      if ((not(j == i / j)) && j > 1) {
        dp[i] += dp[i / j];
        dp[i] %= m;
      }
    }
    sum += dp[i];
    sum %= m;
  }
  cout << dp[n] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
