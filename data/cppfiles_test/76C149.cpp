#include <bits/stdc++.h>
using namespace std;
long long dp[300000];
signed main() {
  long long n, mod;
  scanf("%lld %lld", &n, &mod);
  dp[1] = 1;
  dp[2] = -1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = (dp[i] + 2 * dp[i - 1] + 1) % mod;
    for (long long j = 2 * i; j <= n; j += i)
      dp[j] = (dp[j] + dp[i] - dp[i - 1]) % mod;
  }
  printf("%lld", (dp[n] + mod) % mod);
}
