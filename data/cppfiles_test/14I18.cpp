#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 5;
const int INF = 0x3f3f3f3f;
int a[maxn];
int dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + (a[i] == i);
      for (int j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        if (a[i] + j == i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
      }
    }
    int ma = INF;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (dp[i][j] >= k) ma = min(ma, j);
      }
    }
    if (ma == INF)
      cout << -1 << endl;
    else
      cout << ma << endl;
  }
}
