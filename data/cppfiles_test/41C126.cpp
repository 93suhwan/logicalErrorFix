#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string perm[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  int dp[n + 1][6];
  for (int j = 0; j < 6; j++) {
    dp[0][j] = 0;
    for (int i = 0; i < n; i++) {
      dp[i + 1][j] = dp[i][j];
      char c = perm[j][i % 3];
      if (c != s[i]) dp[i + 1][j]++;
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    int ans = INT_MAX;
    for (int j = 0; j < 6; j++) {
      int t = dp[r][j] - dp[l - 1][j];
      ans = min(ans, t);
    }
    cout << ans << '\n';
  }
}
int main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
