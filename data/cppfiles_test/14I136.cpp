#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;
int n, k, a[N], dp[N][N];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
    if (a[i] <= i)
      dp[i][i - a[i]] = max(dp[i][i - a[i]], dp[i - 1][i - a[i]] + 1);
  }
  for (int i = 1; i <= n; i++) {
    if (dp[n][i] >= k) {
      cout << i << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
}
