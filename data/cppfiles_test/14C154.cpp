#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e3 + 5;
const long long inf = 0x3f3f3f3f;
struct node {
  long long len;
  long long l, r;
};
long long n, k;
long long dp[maxn][maxn];
long long a[maxn];
void solve() {
  cin >> n >> k;
  for (long long i = 0; i < n + 1; i++)
    for (long long j = 0; j < n + 1; j++) dp[i][j] = 0;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= i; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
    }
    dp[i + 1][a[i + 1]] = max(dp[i + 1][a[i + 1]], dp[i][a[i + 1] - 1] + 1);
  }
  long long ans = -1;
  for (long long i = n; i >= 0; i--)
    if (dp[n][i] >= k) {
      ans = n - i;
      break;
    }
  cout << ans << '\n';
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
