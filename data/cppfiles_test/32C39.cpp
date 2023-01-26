#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n), p(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    p[0] = a[0];
    for (long long i = 1; i < n; i++) {
      p[i] = p[i - 1] + a[i];
    }
    long long max_k = 1;
    while ((max_k * (max_k + 1)) / 2 < n) max_k++;
    vector<vector<long long>> dp(n + 1, vector<long long>(max_k + 1, -1));
    long long ans = 1;
    for (long long i = n - 1; i >= 0; i--) {
      long long k;
      dp[i][1] = max(dp[i + 1][1], a[i]);
      for (k = 2; k <= max_k; k++) {
        long long j = i + k - 1;
        if (j >= n) break;
        long long s = p[j];
        if (i > 0) s -= p[i - 1];
        dp[i][k] = dp[i + 1][k];
        if (s < dp[j + 1][k - 1]) {
          dp[i][k] = max(dp[i + 1][k], s);
        }
      }
      for (k = 1; k <= max_k; k++) {
        if (dp[i][k] == -1) break;
      }
      ans = max(ans, k - 1);
    }
    cout << ans << "\n";
  }
}
