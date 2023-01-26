#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int a[maxn], dp[maxn][maxn];
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) dp[i][j] = 0;
    }
    int ans = maxn;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        if (!j)
          dp[i][j] = (a[i] == i - j);
        else
          dp[i][j] = max(dp[i - 1][j] + (a[i] == i - j), dp[i - 1][j - 1]);
        if (dp[i][j] >= k) ans = min(ans, j);
      }
    }
    cout << (ans == maxn ? -1 : ans) << endl;
  }
  return 0;
}
