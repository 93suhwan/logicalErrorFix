#include <bits/stdc++.h>
using namespace std;
long long dp[100005][450];
long long a[100005];
long long sum[100005];
int ans;
long long n;
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 450; j++) {
      dp[i][j] = 0;
    }
  }
}
void solve() {
  cin >> n;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sum[n] = a[n];
  for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + a[i];
  dp[n][1] = a[n];
  ans = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i][1] = max(dp[i + 1][1], a[i]);
    for (int j = 2; j <= 450 && i + j <= n; j++) {
      dp[i][j] = dp[i + 1][j];
      if (dp[i + j][j - 1] != 0 && sum[i] - sum[i + j] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], sum[i] - sum[i + j]);
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
