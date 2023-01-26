#include <bits/stdc++.h>
using namespace std;
long long dp[200100], suf[200100];
signed main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  dp[n] = 1;
  suf[n] = 1;
  long long cur = 1;
  for (long long i = n - 1; i >= 1; i--) {
    for (long long j = 2; j * i <= n; j++) {
      long long fir = j * i;
      long long sec = (j) * (i + 1);
      dp[i] += (suf[fir] - suf[sec]) % m;
      dp[i] %= m;
    }
    dp[i] += cur;
    dp[i] %= m;
    cur %= m;
    suf[i] += suf[i + 1];
    suf[i] %= m;
    suf[i] += dp[i];
    suf[i] %= m;
    cur += dp[i];
    cur %= m;
  }
  cout << dp[1];
}
