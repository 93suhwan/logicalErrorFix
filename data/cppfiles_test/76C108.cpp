#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  long long pref = 0;
  for (long long i = 2; i <= n; i++) {
    dp[i] = pref + dp[i - 1] + dp[1];
    dp[i] %= m;
    pref += dp[i - 1] + dp[1];
    pref %= m;
    for (long long j = 2; j * j <= i; j++) {
      if (i % j) continue;
      dp[i] += dp[j];
      dp[i] -= dp[j - 1];
      pref += dp[j] - dp[j - 1];
      while (pref < 0) pref += m;
      while (dp[i] < 0) dp[i] += m;
      pref %= m;
      dp[i] %= m;
      long long k = i / j;
      if (j * j == i) continue;
      dp[i] += dp[k];
      dp[i] -= dp[k - 1];
      pref += dp[k] - dp[k - 1];
      while (pref < 0) pref += m;
      while (dp[i] < 0) dp[i] += m;
      pref %= m;
      dp[i] %= m;
    }
  }
  cout << dp[n] << endl;
}
