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
  int maxval = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxval = max(maxval, a[i]);
  }
  maxval *= 2;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= maxval; j++) {
      dp[i][j] = maxval * 2;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= maxval; j++) {
      if (dp[i][j] == maxval * 2) {
        continue;
      }
      dp[i + 1][max(0, j - a[i])] =
          min(dp[i + 1][max(0, j - a[i])], dp[i][j] + a[i]);
      if (j + a[i] <= maxval) {
        dp[i + 1][j + a[i]] = min(dp[i + 1][j + a[i]], max(0, dp[i][j] - a[i]));
      }
    }
  }
  int ans = maxval;
  for (int i = 0; i <= maxval; i++) {
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
