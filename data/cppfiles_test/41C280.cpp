#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string base[7] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<int>> dp(6, vector<int>(n + 1, 0));
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      if (base[i][j % 3] == s[j]) {
        if (j > 0) dp[i][j] = dp[i][j - 1];
      } else {
        if (j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i][j - 1] + 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    r--, l--;
    int ans = INT_MAX;
    if (l == 0) {
      for (int j = 0; j < 6; j++) {
        ans = min(ans, dp[j][r]);
      }
    } else {
      for (int j = 0; j < 6; j++) {
        ans = min(ans, dp[j][r] - dp[j][l - 1]);
      }
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
