#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 2001, MOD = 1e9 + 7;
int t, n, k, a[N], dp[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i <= n; ++i) {
      fill(dp[i], dp[i] + n + 1, -1);
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[i][j] == -1) continue;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (j + 1 == a[i]));
      }
    }
    int ans = -1;
    for (int i = n; i > 0; --i) {
      if (dp[n][i] >= k) {
        ans = n - i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
