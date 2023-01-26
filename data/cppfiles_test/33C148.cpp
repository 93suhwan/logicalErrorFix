#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(7);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> dp(n, vector<long long>(513, 1000000000));
  for (long long i = 0; i < n; i++) dp[i][0] = 0;
  dp[0][a[0]] = a[0];
  for (long long i = 1; i < n; i++) {
    dp[i][a[i]] = min(dp[i][a[i]], a[i]);
    for (long long y = 1; y < 512; y++) {
      dp[i][y] = min(dp[i][y], dp[i - 1][y]);
      if (dp[i - 1][y] != 1000000000 && dp[i - 1][y] < a[i]) {
        dp[i][y ^ a[i]] = min(dp[i][y ^ a[i]], a[i]);
      }
    }
  }
  long long res = 0;
  for (long long i = 0; i < 513; i++) {
    if (dp[n - 1][i] != 1000000000) {
      res++;
    }
  }
  cout << res << "\n";
  for (long long i = 0; i < 513; i++) {
    if (dp[n - 1][i] != 1000000000) {
      cout << i << " ";
    }
  }
}
