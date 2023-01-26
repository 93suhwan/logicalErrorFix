#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
mt19937 rnd(time(0));
const long long INF = 1e18;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < n; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + (v[i] == (i - j)));
      dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
    }
  }
  long long ans = INT_MAX;
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n; j++) {
      if (dp[i][j] >= k) {
        ans = min(ans, j);
      }
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  long long T = 1;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return 0;
}
