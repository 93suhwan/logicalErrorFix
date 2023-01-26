#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int a[maxn];
int dp[10005][2005];
int l[2][2005], r[2][2005];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, 0x3f3f3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (dp[i][j] == 0x3f3f3f) continue;
      dp[i + 1][max(0, j - a[i])] =
          min(dp[i + 1][max(0, j - a[i])], dp[i][j] + max(0, a[i] - j));
      if (j + a[i] <= 2000) {
        dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(dp[i][j], a[i]));
      }
    }
  }
  int ans = 2000;
  for (int i = 0; i <= 2000; i++) {
    ans = min(ans, dp[n][i] + i);
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
