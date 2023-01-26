#include <bits/stdc++.h>
using namespace std;
namespace KMP {
vector<int> nxt;
void get_next(string& s) {
  nxt.resize(s.length());
  nxt[0] = -1;
  for (int i = 1, j = -1; i < s.length(); i++) {
    while (j != -1 && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i]) ++j;
    nxt[i] = j;
  }
}
}  // namespace KMP
using namespace KMP;
class Solution {
 private:
  const int inf = 0x3f3f3f3f;
  int n, m;
  string a, b;
  ;

 public:
  void solveOne() {
    cin >> n >> m;
    cin >> a >> b;
    get_next(b);
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(m + 1, vector<int>(n - m + 2, inf)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= n - m + 1; k++) {
          if (dp[i][j][k] == inf) continue;
          int tj = (j == m ? nxt[m - 1] : j - 1);
          while (tj != -1 && b[tj + 1] != a[i]) tj = nxt[tj];
          if (b[tj + 1] == a[i]) ++tj;
          if (tj + 1 == m) {
            if (k != n - m + 1)
              dp[i + 1][tj + 1][k + 1] =
                  min(dp[i + 1][tj + 1][k + 1], dp[i][j][k]);
          } else {
            dp[i + 1][tj + 1][k] = min(dp[i + 1][tj + 1][k], dp[i][j][k]);
          }
          char v = '0';
          if (a[i] == '0') v = '1';
          tj = (j == m ? nxt[m - 1] : j - 1);
          while (tj != -1 && b[tj + 1] != v) tj = nxt[tj];
          if (b[tj + 1] == v) ++tj;
          if (tj + 1 == m) {
            if (k != n - m + 1)
              dp[i + 1][tj + 1][k + 1] =
                  min(dp[i + 1][tj + 1][k + 1], dp[i][j][k] + 1);
          } else {
            dp[i + 1][tj + 1][k] = min(dp[i + 1][tj + 1][k], dp[i][j][k] + 1);
          }
        }
      }
    }
    for (int k = 0; k <= n - m + 1; k++) {
      int ans = inf;
      for (int j = 0; j <= m; j++) {
        ans = min(ans, dp[n][j][k]);
      }
      cout << (ans == inf ? -1 : ans) << " ";
    }
    cout << endl;
  }
  void solve() {
    int t = 1;
    for (int i = 0; i < t; ++i) {
      solveOne();
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution solver;
  solver.solve();
  return 0;
}
