#include <bits/stdc++.h>
long long mod = 998244353;
using namespace std;
long long bpow(long long a, long long deg) {
  if (deg == 0) return 1;
  if (deg % 2 != 0)
    return (bpow(a, deg - 1) * a) % mod;
  else {
    long long b = bpow(a, deg / 2);
    return (b * b) % mod;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<long long>> dp(n, vector<long long>(3, 0));
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        dp[i][0] = 1;
      else if (a[i] == 1)
        cnt++;
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] == a[j]) dp[i][0] += dp[j][0] + dp[j][1] + dp[j][2];
      }
      for (int j = 0; j < i; j++) {
        if (a[i] == a[j] + 1) dp[i][1] += dp[j][0] + dp[j][1];
      }
      for (int j = 0; j < i; j++) {
        if (a[i] == a[j] + 2) dp[i][2] += dp[j][0] + dp[j][1] + dp[j][2];
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        ans += dp[i][j];
        ans %= mod;
      }
    }
    ans += (bpow(2, cnt) - 1 + mod) % mod;
    ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
