#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2001, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2000; j++) {
        if (dp[i][j] == 1e9) continue;
        if (j + a[i] <= 2000) {
          dp[i + 1][j + a[i]] =
              min(dp[i + 1][j + a[i]], max(dp[i][j], j + a[i]));
        }
        if (j - a[i] >= 0) {
          dp[i + 1][j - a[i]] = min(dp[i + 1][j - a[i]], dp[i][j]);
        } else {
          dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + a[i] - j);
        }
      }
    }
    int res = 1e9;
    for (int i = 0; i <= 2000; i++) {
      res = min(res, dp[n][i]);
    }
    cout << res << "\n";
  }
}
