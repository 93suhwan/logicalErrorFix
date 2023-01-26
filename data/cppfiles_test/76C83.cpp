#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  long long prefSum = dp[1];
  for (long long(i) = (2); (i) < (n + 1); ++(i)) {
    dp[i] = prefSum;
    for (long long j = 1; j * j <= i; ++j) {
      dp[i] = (dp[i] + (dp[j] * ((i / j) - (i / (j + 1)))) % m) % m;
      if (j != i / j && j > 1) {
        dp[i] = (dp[i] + dp[i / j]) % m;
      }
    }
    prefSum = (prefSum + dp[i]) % m;
  }
  cout << dp[n];
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  while (tc--) {
    solve();
    cout << '\n';
  }
  return 0;
}
