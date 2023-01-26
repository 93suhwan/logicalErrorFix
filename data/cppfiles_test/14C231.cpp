#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) {
      cin >> i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0].push_back(0);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (i - j == v[i - 1]) {
          dp[i][j] = dp[i - 1][j] + 1;
        } else {
          if (j > 0) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
          } else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    bool flag = true;
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] >= k) {
        flag = false;
        cout << i << '\n';
        break;
      }
    }
    if (flag) {
      cout << "-1\n";
    }
  }
}
