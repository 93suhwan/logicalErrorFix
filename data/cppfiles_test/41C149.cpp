#include <bits/stdc++.h>
using namespace std;
int n, m, dp[6][200050];
char s[200050];
string x[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
int main() {
  cin >> n >> m;
  cin >> s + 1;
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j - 1] + (s[j] != x[i][(j - 1) % 3]);
    }
  }
  for (int i = 1; i <= m; i++) {
    int l, r, ans = 0x3f3f3f3f;
    cin >> l >> r;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, dp[i][r] - dp[i][l - 1]);
    }
    cout << ans << endl;
  }
}
