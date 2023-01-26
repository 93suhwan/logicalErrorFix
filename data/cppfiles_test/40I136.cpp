#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int mp[3][maxn], dp[3][maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m;
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= m; j++) cin >> mp[i][j];
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= m; j++) dp[i][j] = dp[i][j - 1] + mp[i][j];
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
      int cnt = max(dp[1][i - 1], dp[0][m] - dp[0][i]);
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }
  return 0;
}
