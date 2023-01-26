#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int v[500005];
long long dp[500005], dp1[500005];
int main() {
  int t, w, i, j, a, b, c, d, n;
  cin >> t;
  for (w = 0; w < t; w++) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> v[i];
      dp[i] = dp1[i] = 0;
    }
    dp[n + 1] = dp1[n + 1] = 0;
    long long tot = 0;
    dp[0] = 1;
    for (i = 1; i <= n; ++i) {
      v[i]++;
      if (v[i] == 1) {
        dp[1] = dp[1] * 2 + 1;
        if (dp[1] >= MOD) dp[1] -= MOD;
        continue;
      }
      tot += dp[v[i]] + dp[v[i] - 1];
      tot += dp1[v[i] - 1] + dp[v[i] - 2];
      dp[v[i]] = dp[v[i]] * 2 + dp[v[i] - 1];
      dp[v[i]] %= MOD;
      dp1[v[i] - 1] = dp1[v[i] - 1] * 2 + dp[v[i] - 2];
      dp1[v[i] - 1] %= MOD;
      tot %= MOD;
      while (dp[v[i]] >= MOD) dp[v[i]] -= MOD;
      while (dp1[v[i] - 1] >= MOD) dp1[v[i] - 1] -= MOD;
    }
    tot += dp[1];
    tot %= MOD;
    printf("%d\n", tot);
  }
  return 0;
}
