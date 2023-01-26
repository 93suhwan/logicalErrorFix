#include <bits/stdc++.h>
using namespace std;
long long dp[100005][500];
long long a[100005];
long long sum[100005];
int ans;
long long n;
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 500; j++) {
      dp[i][j] = 0;
    }
  }
}
void solve() {
  ans = 1;
  cin >> n;
  init();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  dp[n][1] = a[n];
  for (int i = n - 1; i > 0; i--) {
    dp[i][1] = max(dp[i + 1][1], a[i]);
    for (int j = 2; j <= 500 && i + j <= n; j++) {
      dp[i][j] = dp[i + 1][j];
      long long dx = sum[j + i - 1] - sum[i - 1];
      long long dp_ = dp[i + j][j - 1];
      if (sum[j + i - 1] - sum[i - 1] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], sum[j + i - 1] - sum[i - 1]);
        ans = max(ans, j);
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
