#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int maxn = 2e3 + 5;
const int INF = 0x3f3f3f3f;
int dp[2][maxn];
void solve() {
  int n;
  cin >> n;
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0] = 0;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    int u = i & 1;
    fill(dp[u ^ 1], dp[u ^ 1] + maxn, INF);
    for (int j = 0; j < maxn; j++) {
      if (dp[u][j] == INF) continue;
      int p = max(j - x, 0);
      dp[u ^ 1][p] = min(dp[u ^ 1][p], dp[u][j] + x);
      p = j + x;
      if (p >= maxn) continue;
      dp[u ^ 1][p] = min(dp[u ^ 1][p], max(0, dp[u][j] - x));
    }
  }
  int u = (n + 1) & 1;
  int ans = INF;
  for (int i = 0; i < maxn; i++) ans = min(ans, i + dp[u][i]);
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
