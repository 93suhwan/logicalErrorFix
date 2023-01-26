#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k = 0, ans = 0;
    cin >> n;
    long long a[n], sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
      a[i] = sum;
    }
    while (k * (k + 1) / 2 <= n) ++k;
    int dp[n][k];
    memset(dp, -1, sizeof(dp));
    dp[n - 1][1] = a[n - 1] - (n - 2 >= 0 ? a[n - 2] : 0);
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 1; i + j * (j + 1) / 2 <= n; ++j) {
        dp[i][j] = dp[i + 1][j];
        int seg = a[i + j - 1] - (i ? a[i - 1] : 0);
        if (seg < dp[i + j][j - 1]) dp[i][j] = max(dp[i][j], seg);
      }
    }
    for (int i = 0; i < k; ++i)
      if (dp[0][i] != -1) ans = max(ans, i);
    cout << ans << '\n';
  }
}
