#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int a[N];
int b[N];
int dp[N][N];
void work() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) b[i] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) dp[i][0] = dp[i - 1][0] + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j] = max(dp[i - 1][j] + (a[i] + j == i), dp[i - 1][j - 1]);
    }
    dp[i][i] = 0;
  }
  int ans = n + 1;
  for (int j = 0; j <= n; j++) {
    if (dp[n][j] >= k) ans = min(ans, j);
  }
  if (ans == n + 1)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    work();
  }
}
