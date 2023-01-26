#include <bits/stdc++.h>
const int N = 3e5 + 7;
const double eps = 1e-6;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, mod;
  cin >> n >> mod;
  long long dp[n + 1];
  memset(dp, 0, sizeof(dp));
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (i == 2)
      dp[i] = 2;
    else {
      dp[i] += 2 * dp[i - 1];
      dp[i]++;
      dp[i] = dp[i] % mod;
    }
    int v = dp[i] - dp[i - 1] + mod;
    for (int j = 2 * i; j <= n; j += i) dp[j] += v;
  }
  cout << dp[n] << "\n";
}
