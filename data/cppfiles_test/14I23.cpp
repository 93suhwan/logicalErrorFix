#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, n, m;
    cin >> n >> k;
    long long a[n + 1];
    a[0] = 0;
    for (i = 1; i <= n; i++) cin >> a[i];
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      if (a[i] == i) dp[i]++;
    }
    long long ans = INT_MAX;
    for (i = 1; i <= n; i++) {
      for (j = i; j >= 1; j--) {
        if (a[i] == j) break;
      }
      if (a[i] == j) {
        m = i - j;
        long long x = dp[j - 1] + 1;
        for (j = i + 1; j <= n; j++) {
          if (a[j] == (j - m)) x++;
        }
        if (x >= k) {
          ans = min(ans, m);
        }
      }
    }
    if (ans == INT_MAX)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
}
