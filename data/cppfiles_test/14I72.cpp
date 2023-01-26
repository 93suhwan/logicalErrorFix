#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
#pragma GCC target("avx2")
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int> > dp(n + 5, vector<int>(n + 5, 0));
  int a[n + 6];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 0;
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      if (dp[i][j] >= k) {
        ans = min(ans, j);
      }
    }
  }
  if (ans == 1e9) {
    cout << -1;
    return;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
