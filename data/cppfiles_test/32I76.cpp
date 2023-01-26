#include <bits/stdc++.h>
using namespace std;
const int MAXK = 455;
long long dp[100005][MAXK];
long long a[100005];
long long sum[100005];
long long ans = 0;
long long n;
void init() {
  for (int i = 0; i <= n; i++) sum[i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= MAXK; j++) {
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
  }
  sum[n] = a[n];
  for (int i = n - 1; i > 0; i--) sum[i] = sum[i + 1] + a[i];
  dp[n][1] = a[n];
  for (int i = n - 1; i > 0; i--) {
    dp[i][1] = max(dp[i + 1][1], a[i]);
    for (int j = 2; j <= MAXK && i + j <= n; j++) {
      dp[i][j] = dp[i + 1][j];
      if (sum[i] - sum[i + j] < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], sum[i] - sum[i + j]);
        ans = max(ans, (long long)j);
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
