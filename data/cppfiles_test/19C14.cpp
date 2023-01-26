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
long long dp[2][3505];
int main() {
  init();
  long long t;
  cin >> t;
  while (t--) {
    memset(dp, 1, sizeof dp);
    dp[0][0] = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      long long b = i % 2;
      memset(dp[!b], 1, sizeof dp[!b]);
      for (int j = 0; j < 3500; ++j) {
        long long l = dp[b][j] + max((long long)0, x - j);
        long long st = max((long long)0, j - x);
        if (st < 3500 && l < 3500) {
          dp[!b][st] = min(dp[!b][st], l);
        }
        l = max(dp[b][j], x + j);
        st = j + x;
        if (st < 3500 && l < 3500) {
          dp[!b][st] = min(dp[!b][st], l);
        }
      }
    }
    long long ans = 1e18;
    for (int i = 0; i < 3500; ++i) {
      ans = min(ans, dp[n % 2][i]);
    }
    cout << ans << "\n";
  }
}
