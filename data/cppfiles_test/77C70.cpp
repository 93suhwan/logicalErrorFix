#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int n;
long long m;
long long dp[4000005];
int main() {
  cin >> n >> m;
  memset(dp, 0LL, sizeof(dp));
  dp[n] = 1LL;
  for (int i = n - 1; i >= 1; --i) {
    dp[i] = (dp[i] + dp[i + 1]) % m;
    for (int j = 2; j <= n / i; ++j) {
      long long j2 = min((long long)n, (long long)j * (long long)(i + 1) - 1);
      long long det = dp[j * i];
      if (j2 < n) det = (det - dp[j * (i + 1)] + m) % m;
      dp[i] = (dp[i] + det) % m;
    }
    dp[i] = (dp[i] + dp[i + 1]) % m;
  }
  long long ans = (dp[1] - dp[2] + m) % m;
  printf("%lld\n", ans);
  return 0;
}
