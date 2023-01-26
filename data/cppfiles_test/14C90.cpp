#include <bits/stdc++.h>
using namespace std;
const int N = 3e3;
const int inf = 1e8;
int dp[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (a[0] == 0) ? 1 : 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j > i) break;
        int res = dp[i - 1][j];
        if (a[i] == i - j) res++;
        dp[i][j] = max(dp[i][j], res);
      }
      for (int j = 0; j < n - 1; j++) {
        if (j - 1 > i) break;
        int res = dp[i - 1][j];
        dp[i][j + 1] = max(res, dp[i][j + 1]);
      }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] < m) continue;
        ans = min(ans, j);
      }
    }
    if (ans == inf)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
