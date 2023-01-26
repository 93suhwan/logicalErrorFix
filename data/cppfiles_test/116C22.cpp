#include <bits/stdc++.h>
using namespace std;
long long int k = 998244353;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % k;
  while (y > 0) {
    if (y & 1) res = (res * x) % k;
    y = y >> 1;
    x = (x * x) % k;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    long long int a[n];
    vector<pair<long long int, long long int>> dp(n + 5, {0, 0});
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0].first = 1;
    for (int i = 0; i < n; i++) {
      long long int curr = a[i];
      curr--;
      if (curr >= 0) {
        long long int temp = dp[curr].first + dp[curr].second;
        temp %= k;
        dp[curr].second += temp;
        dp[curr].second %= k;
      }
      curr += 2;
      dp[curr].second += dp[curr].second;
      dp[curr].first += dp[curr].first;
      dp[curr].second %= k;
      dp[curr].first %= k;
      dp[curr].first += dp[curr - 1].first;
      dp[curr].first %= k;
    }
    long long int ans = 0;
    for (int i = 0; i <= n + 2; i++) {
      ans += dp[i].first;
      ans %= k;
      ans += dp[i].second;
      ans %= k;
    }
    ans--;
    ans %= k;
    if (ans < 0) ans += k;
    cout << ans;
    cout << "\n";
  }
  return 0;
}
