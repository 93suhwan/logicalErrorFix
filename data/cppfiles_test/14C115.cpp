#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 100;
const int INF = 1e9;
int dp[MAXN][MAXN];
int fillDP(int *a, int n, int k) {
  dp[0][0] = a[0] == 1;
  dp[0][1] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i - 1][0] + (a[i] == i + 1);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i - 1][j] + (a[i] == i + 1 - j), dp[i - 1][j - 1]);
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i <= n; ++i) {
    if (dp[n - 1][i] >= k) {
      ans = min(ans, i);
    }
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      fill(dp[i], dp[i] + MAXN, -INF);
    }
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = fillDP(a, n, k);
    if (res == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}
