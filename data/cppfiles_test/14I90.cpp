#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2000 + 5;
const long long INF = 0x3f3f3f3f;
long long a[maxn];
long long dp[maxn][maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long p = 1; p <= t; p++) {
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) dp[i][j] = 0;
    }
    for (long long i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + (a[i] == i);
      for (long long j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        if (a[i] + j == i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
      }
    }
    long long ma = INF;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        if (dp[i][j] >= k) ma = min(ma, j);
      }
    }
    if (ma == INF)
      cout << -1 << endl;
    else
      cout << ma << endl;
    if (p == 68)
      for (long long i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
  }
}
