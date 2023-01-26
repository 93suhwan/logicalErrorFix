#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long a[3005], dp[3005][3005], locc[3005], rocc[3005], go_l[3005],
    go_r[3005];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    locc[i] = 0;
    rocc[i] = n + 1;
  }
  for (long long i = 1; i <= n; i++) {
    go_l[i] = locc[a[i]];
    locc[a[i]] = i;
  }
  for (long long i = n; i >= 1; i--) {
    go_r[i] = rocc[a[i]];
    rocc[a[i]] = i;
  }
  for (long long d = 2; d <= n; d++) {
    for (long long l = 1; l <= n - d + 1; l++) {
      long long r = l + d - 1;
      dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
      dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + (d > 2) + (a[l] != a[r]));
      if (a[l] == a[r]) {
        for (long long mid = go_r[l]; mid < r; mid = go_r[mid])
          dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
      } else {
        for (long long mid = go_r[l]; mid < r; mid = go_r[mid])
          dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r] + 1);
        for (long long mid = go_l[r]; mid > l; mid = go_l[mid])
          dp[l][r] = min(dp[l][r], dp[l][mid - 1] + dp[mid][r] + 1);
      }
    }
  }
  cout << dp[1][n] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
