#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long so() {
  long long n, m;
  cin >> n >> m;
  long long mod = m;
  vector<long long> dp(n * 2 + 1), s(n * 2 + 1);
  dp[1] = 1;
  dp[2] = dp[1] + 1;
  s[1] = 1;
  s[2] = 3;
  for (long long i = (3); i <= (n); ++i) {
    long long t = sqrt(i);
    dp[i] = (dp[i] + s[i - 1]) % mod;
    for (long long j = 2, rt; j <= i; j = rt + 1) {
      rt = min(i / (i / j), n);
      dp[i] = (dp[i] + (rt - j + 1) * dp[i / j] % mod) % mod;
    }
    s[i] = (s[i - 1] + dp[i]) % mod;
  }
  return dp[n];
}
signed main() { cout << so() << '\n'; }
