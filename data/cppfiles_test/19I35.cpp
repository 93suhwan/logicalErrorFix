#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int t, n;
pair<int, int> dp[2][2010];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= 2000; i++) dp[0][i] = dp[1][i] = {-1, -1};
    dp[0][1000] = {1000, 1000};
    int op = 0;
    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      for (int j = 0; j <= 2000; j++) {
        if (dp[op][j].first != -1) {
          if (j - x >= 0) {
            if (dp[op ^ 1][j - x].first != -1) {
              int last = dp[op ^ 1][j - x].second - dp[op ^ 1][j - x].first;
              int now = dp[op][j].second - min(j - x, dp[op][j].first);
              if (now < last)
                dp[op ^ 1][j - x] = {min(j - x, dp[op][j].first),
                                     dp[op][j].second};
            } else
              dp[op ^ 1][j - x] = {min(j - x, dp[op][j].first),
                                   dp[op][j].second};
          }
          if (j + x <= 2000) {
            if (dp[op ^ 1][j + x].first == -1)
              dp[op ^ 1][j + x] = {dp[op][j].first,
                                   max(j + x, dp[op][j].second)};
            else {
              int last = dp[op ^ 1][j + x].second - dp[op ^ 1][j + x].first;
              int now = max(dp[op][j].second, j + x) - dp[op][j].first;
              if (now < last)
                dp[op ^ 1][j + x] = {dp[op][j].first,
                                     max(j + x, dp[op][j].second)};
            }
          }
          dp[op][j] = {-1, -1};
        }
      }
      op ^= 1;
    }
    int ans = 3000;
    for (int i = 0; i <= 2000; i++)
      if (dp[op][i].first != -1) {
        ans = min(dp[op][i].second - dp[op][i].first, ans);
      }
    cout << ans << '\n';
  }
  return 0;
}
