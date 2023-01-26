#include <bits/stdc++.h>
using namespace std;
long long a[2005];
long long dp[2005][2005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        dp[i][j] = 0;
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j < i; j++) {
        dp[i][j] = dp[i - 1][j - 1];
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
      }
    }
    long long ans = -1;
    for (long long j = 0; j <= n; j++) {
      if (dp[n][j] >= k) {
        ans = j;
        break;
      }
    }
    cout << ans << "\n";
  }
}
