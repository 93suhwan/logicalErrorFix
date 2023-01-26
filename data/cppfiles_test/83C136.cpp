#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  string s;
  cin >> n;
  cin >> s;
  long long arr[n + 1][n + 1];
  for (long long i = 1; i < n + 1; i++) {
    if (s[i - 1] == s[n - 1])
      arr[i][n] = 1;
    else
      arr[i][n] = 0;
  }
  for (long long i = n - 2; i >= 1; i--) {
    for (long long j = i + 1; j < n; j++) {
      if (s[i - 1] == s[j - 1])
        arr[i][j] = 1 + arr[i + 1][j + 1];
      else
        arr[i][j] = 0;
    }
  }
  long long dp[n + 1];
  for (long long i = 0; i < n + 1; i++) dp[i] = 0;
  dp[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    long long t = 0;
    for (long long j = i + 1; j <= n; j++) {
      long long x = arr[i][j];
      if (j - 1 + x >= n) continue;
      bool y = s[i - 1 + x] > s[j - 1 + x];
      if (!y) t = max(t, dp[j] - x);
    }
    dp[i] = n - i + 1 + t;
  }
  sort(dp, dp + n + 1);
  cout << dp[n] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
