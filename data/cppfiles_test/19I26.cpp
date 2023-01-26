#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    const long long me = 20;
    vector<vector<long long>> dp(n + 1, vector<long long>(me, LLONG_MAX / 2));
    for (long long i = 0; i < me; ++i) dp[n][i] = 0;
    for (long long i = n - 1; i >= 0; --i)
      for (long long j = 0; j < me; ++j)
        if (dp[i + 1][j] != LLONG_MAX / 2) {
          if (a[i] + j < me)
            dp[i][a[i] + j] =
                min(dp[i][a[i] + j], max((long long)0, dp[i + 1][j] - a[i]));
          if (a[i] + dp[i + 1][j] < me)
            dp[i][a[i] + dp[i + 1][j]] =
                min(dp[i][a[i] + dp[i + 1][j]], max((long long)0, j - a[i]));
        }
    long long ans = LLONG_MAX / 2;
    for (long long i = 0; i < me; ++i)
      if (dp[0][i] < LLONG_MAX / 2) ans = min(ans, i + dp[0][i]);
    cout << ans << endl;
  }
}
