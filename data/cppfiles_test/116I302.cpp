#include <bits/stdc++.h>
using namespace std;
long long powerr[1000005];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  powerr[0] = 1;
  for (long long i = 1; i < 1000005; i++) {
    powerr[i] = powerr[i - 1] * 2;
    powerr[i] %= 998244353;
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long freq_dp[n + 8];
    long long freq[n + 8];
    memset(freq, 0, sizeof(freq));
    memset(freq_dp, 0, sizeof(freq_dp));
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long dp[n + 8];
    memset(dp, 0, sizeof(dp));
    for (long long i = n - 1; i >= 0; i--) {
      dp[i] = (freq_dp[a[i]] + freq_dp[a[i] + 1] + powerr[freq[a[i] + 2]]);
      dp[i] %= 998244353;
      freq_dp[a[i]] += dp[i];
      freq_dp[a[i]] %= 998244353;
      freq[a[i]]++;
    }
    long long ans = 0;
    ans = powerr[freq[1]] - 1;
    ans += 998244353;
    ans %= 998244353;
    for (long long i = 0; i < n; i++) {
      if (a[i] == 0) {
        ans += dp[i];
        ans %= 998244353;
      }
    }
    cout << ans << "\n";
  }
}
