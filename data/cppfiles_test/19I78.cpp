#include <bits/stdc++.h>
using namespace std;
const long long int oo = 1e9;
const int MAXN = 1e4 + 5;
int t, n, a[2005];
long long int dp[MAXN][2005];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  cin >> t;
  while (t--) {
    cin >> n;
    int MAXA = 0;
    for (int i = 0; i < n; i++) cin >> a[i], MAXA = max(MAXA, a[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2 * MAXA; j++) dp[i][j] = oo;
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2 * MAXA; j++) {
        if (dp[i][j] >= oo) continue;
        dp[i + 1][max(0, j - a[i])] =
            min(dp[i + 1][max(0, j - a[i])], dp[i][j] + a[i]);
        if ((j + a[i]) <= (2 * MAXN))
          dp[i + 1][j + a[i]] =
              min(dp[i + 1][j + a[i]], max(0LL, dp[i][j] - a[i]));
      }
    }
    long long int ans = oo;
    for (int i = 0; i <= 2 * MAXA; i++) ans = min(dp[n][i] + i, ans);
    cout << ans << "\n";
  }
  return 0;
}
