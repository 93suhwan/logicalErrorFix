#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> h(n + 1), dp(n + 2, vector<int>(n + 2, -1));
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      h[v[i]].push_back(i + 1);
    }
    for (int l = 1; l <= n; l++) {
      for (int i = 1; i <= n - l + 1; i++) {
        dp[i][i + l - 1] = dp[i][i + l - 2] + 1;
        for (int &x : h[v[i + l - 2]]) {
          if (x < i || i + l - 2 < x) continue;
          dp[i][i + l - 1] =
              min(dp[i][i + l - 1], dp[i][x] + dp[x + 1][i + l - 2] + 1);
        }
      }
    }
    cout << dp[1][n] << '\n';
  }
  return 0;
}
