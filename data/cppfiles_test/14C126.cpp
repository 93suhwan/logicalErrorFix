#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(n + 1));
    dp[0][1] = (v[0] == 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= i + 1; ++j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (v[i] == j));
      }
    }
    int ans = -1;
    for (int i = 0; i <= n; ++i) {
      if (dp[n - 1][n - i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
}
