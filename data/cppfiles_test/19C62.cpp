#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  cout.sync_with_stdio(0);
}
long long en;
long long n, arr[10001], ix = 0;
int main() {
  init();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    en = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      en = max(arr[i], en);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(en * 2 + 3, 1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= en * 2 + 1; ++j) {
        if (dp[i][j] == 1e18) continue;
        long long l = max((long long)0, j - arr[i]);
        dp[i + 1][l] = min(dp[i + 1][l], dp[i][j] + arr[i]);
        long long r = j + arr[i];
        if (r < dp[i].size())
          dp[i + 1][r] =
              min(dp[i + 1][r], max((long long)0, dp[i][j] - arr[i]));
      }
    }
    long long ans = LONG_LONG_MAX;
    for (int j = 0; j < 2 * en + 1; ++j) {
      ans = min(ans, dp[n][j] + j);
    }
    cout << ans << "\n";
  }
}
