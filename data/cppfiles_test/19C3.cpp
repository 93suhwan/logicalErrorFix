#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 2;
const long long M = 2e3 + 2;
const long long inf = 1e10;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  vector<vector<long long>> dp(n + 2, vector<long long>(2100, inf));
  dp[0][0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j <= 2000; ++j) {
      if (dp[i][j] == inf) continue;
      dp[i + 1][max(0ll, j - a[i])] =
          min(dp[i][j] + a[i], dp[i + 1][max(0ll, j - a[i])]);
      if (j + a[i] <= 2000)
        dp[i + 1][j + a[i]] =
            min(max(0ll, dp[i][j] - a[i]), dp[i + 1][j + a[i]]);
    }
  }
  long long ans = 2e3;
  for (long long i = 0; i <= 2000; ++i) ans = min(ans, i + dp[n][i]);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
