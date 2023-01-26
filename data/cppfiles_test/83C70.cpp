#include <bits/stdc++.h>
using namespace std;
const int nax = 5005;
int n;
int dp[nax][nax];
char s[nax];
int lcp[nax][nax];
vector<int> eq[nax];
void solve() {
  cin >> n;
  string x;
  cin >> x;
  for (int i = 0; i < n; i++) s[i + 1] = x[i];
  for (int i = 1; i <= n; i++) dp[1][i] = i;
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) lcp[i][j] = 0;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (i == j) continue;
      lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
    }
  }
  for (int i = 2; i <= n; i++) {
    int maxi = 0;
    for (int j = 1; j < i; j++) {
      if (s[j] < s[i]) maxi = max(maxi, dp[j][n + 1 - j]);
    }
    dp[i][1] = maxi + 1;
    for (int i = 0; i <= n; i++) eq[i].clear();
    for (int j = 1; j < i; j++) {
      int len = lcp[i][j];
      eq[len].push_back(j);
    }
    for (int j = 2; j <= n + 1 - i; j++) {
      dp[i][j] = dp[i][j - 1] + 1;
      for (int pre : eq[j]) {
        dp[i][j] = max(dp[i][j], dp[pre][j]);
      }
      for (int pre : eq[j - 1]) {
        if (s[pre + j - 1] < s[i + j - 1])
          dp[i][j] = max(dp[i][j], dp[pre][n + 1 - pre] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + 1 - i; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
