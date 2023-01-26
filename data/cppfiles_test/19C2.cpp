#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 1e5 + 10;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
inline int lowbit(int x) { return x & (-x); }
int dp[10010][2020];
int a[N];
inline void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 2000; j++) dp[i][j] = INF;
  for (int i = 1; i <= 2000; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (dp[i - 1][j] == INF) continue;
      if (j + a[i] <= 2000)
        dp[i][j + a[i]] = min(dp[i][j + a[i]], max(dp[i - 1][j], j + a[i]));
      if (j - a[i] >= 0)
        dp[i][j - a[i]] = min(dp[i][j - a[i]], dp[i - 1][j]);
      else
        dp[i][0] = min(dp[i][0], dp[i - 1][j] + a[i] - j);
    }
  }
  int res = INF;
  for (int i = 0; i <= 2000; i++) res = min(res, dp[n][i]);
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cout << fixed << setprecision(2);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
