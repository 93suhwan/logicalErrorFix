#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1);
  dp[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (i == 2)
      dp[i] = 2;
    else {
      dp[i] += 2 * dp[i - 1];
      dp[i]++;
      dp[i] %= m;
    }
    long long v = dp[i] - dp[i - 1] + m;
    for (long long j = 2 * i; j <= n; j += i) {
      dp[j] += v;
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
