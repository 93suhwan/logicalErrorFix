#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int N = 2010;
int a[N];
int dp[N][N];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= i; j++) dp[i][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + 1] =
            max(dp[i + 1][j + 1], dp[i][j] + ((a[i + 1] == j + 1) ? 1 : 0));
      }
    int ans = -1;
    for (int i = n; i >= 0; i--)
      if (dp[n][i] >= k) {
        ans = n - i;
        break;
      }
    cout << ans << endl;
  }
}
