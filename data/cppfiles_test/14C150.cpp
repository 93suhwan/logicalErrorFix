#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long _;
  cin >> _;
  while (_--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = (long long)(0); i < (long long)(n); ++i) cin >> a[i];
    long long suf[n][n + 1];
    memset(suf, 0, sizeof(suf));
    for (long long i = (long long)(n - 1); i >= (long long)(0); --i) {
      if (a[i] <= i + 1) suf[i][i + 1 - a[i]]++;
      if (i == n - 1) continue;
      for (long long j = (long long)(0); j < (long long)(n + 1); ++j)
        suf[i][j] += suf[i + 1][j];
    }
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (long long i = (long long)(0); i < (long long)(n); ++i)
      if (a[i] == i + 1) dp[0][0]++;
    for (long long i = (long long)(1); i < (long long)(n + 1); ++i) {
      for (long long j = (long long)(0); j < (long long)(n + 1); ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j and i < n)
          dp[i][j] =
              max(dp[i][j], dp[i - 1][j - 1] + suf[i][j] - suf[i - 1][j - 1]);
      }
    }
    long long ans = -1;
    for (long long i = (long long)(0); i < (long long)(n + 1); ++i) {
      for (long long j = (long long)(0); j < (long long)(n + 1); ++j) {
        if (dp[j][i] >= k) {
          ans = i;
          break;
        }
      }
      if (ans != -1) break;
    }
    cout << ans << '\n';
  }
  return 0;
}
