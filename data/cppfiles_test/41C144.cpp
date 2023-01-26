#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 7;
const int INF = 0x3f3f3f3f;
int n, m;
int main() {
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> dp(6, vector<int>(n + 1));
  for (int(i) = 0; (i) < (int)(6); (i)++) {
    dp[i][0] = 0;
    for (int(j) = 0; (j) < (int)(n); (j)++) {
      dp[i][j + 1] = dp[i][j];
      if (i < 3) {
        if ((s[j] - 'a') != (i + j) % 3) dp[i][j + 1]++;
      } else {
        if ((s[j] - 'a') != ((i - j % 3 + 3) % 3)) dp[i][j + 1]++;
      }
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--;
    int ans = INF;
    for (int(i) = 0; (i) < (int)(6); (i)++) ans = min(ans, dp[i][r] - dp[i][l]);
    cout << ans << endl;
  }
  return 0;
}
