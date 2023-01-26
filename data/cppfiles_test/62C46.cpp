#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(m + 1, vector<int>(2, 0)));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp[i][j][1] = dp[i][j - 1][0] + 1;
      dp[i][j][0] = dp[i - 1][j][1] + 1;
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ans += dp[i][j][0] + dp[i][j][1];
    }
  ans -= n * m;
  int q;
  cin >> q;
  vector<vector<int>> a(n, vector<int>(m, 1));
  auto calc_len = [&](int x, int y, int dx, int dy) {
    int res = 0;
    while (1) {
      x += dx;
      y += dy;
      if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 0) {
        break;
      }
      res++;
      swap(dx, dy);
    }
    return res;
  };
  while (q--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    {
      int x = calc_len(i, j, -1, 0);
      int y = calc_len(i, j, 0, 1);
      ans += (a[i][j] == 1 ? -1 : 1) * ((x + 1) * (y + 1));
    }
    {
      int x = calc_len(i, j, 0, -1);
      int y = calc_len(i, j, 1, 0);
      ans += (a[i][j] == 1 ? -1 : 1) * ((x + 1) * (y + 1));
    }
    ans += (a[i][j] == 1 ? 1 : -1);
    a[i][j] ^= 1;
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
}
