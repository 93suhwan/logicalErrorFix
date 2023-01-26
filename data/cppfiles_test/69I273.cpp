#include <bits/stdc++.h>
using namespace std;
int solve(string s1, string s2) {
  int n = s1.length(), m = s2.length();
  vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
  for (long long int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }
  for (long long int i = 1; i <= m; i++) {
    dp[0][i] = i;
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[n][m];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    long long int n;
    cin >> n;
    int ans = INT_MAX;
    for (long long int j = 0; j <= 30; j++) {
      ans = min(ans, solve(to_string(n), to_string((1 << j))));
    }
    cout << ans << "\n";
  }
  return 0;
}
