#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, p[N][2], dp[N][2][2];
pair<int, int> g[N][2][2];
void cmin(int& x, int y) {
  if (x > y) x = y;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i][1]), p[i][0] = -p[i][1];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 1; j++)
      for (int k = 0; k <= 1; k++) dp[i][j][k] = n + 1;
  dp[1][0][0] = dp[1][0][1] = -n - 1;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= 1; j++)
      for (int k = 0; k <= 1; k++)
        for (int l = 0; l <= 1; l++) {
          int x = (j == 0) ? p[i][k] : dp[i][j][k],
              y = (j == 1) ? p[i][k] : dp[i][j][k];
          if (x > p[i + 1][l] && p[i + 1][l] > y && dp[i + 1][1][l] > x)
            dp[i + 1][1][l] = x, g[i + 1][1][l] = {j, k};
          if (p[i + 1][l] > x && dp[i + 1][0][l] > y)
            dp[i + 1][0][l] = y, g[i + 1][0][l] = {j, k};
        }
  vector<int> ans;
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= 1; j++)
      if (dp[n][i][j] != n + 1) {
        puts("YES");
        pair<int, int> now = g[n][i][j];
        int tmp = n - 1;
        ans.push_back(p[n][j]);
        while (tmp) {
          ans.push_back(p[tmp][now.second]);
          now = g[tmp][now.first][now.second];
          tmp--;
        }
        for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
        puts("");
        return;
      }
  puts("NO");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
