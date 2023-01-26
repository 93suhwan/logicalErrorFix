#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  vector<vector<char>> c(n + 1, vector<char>(m + 1));
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
  vector<vector<int>> p(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
      if ((i == 1 or j == 1) and c[i][j] != 'X') {
        dp[i][j] = 1;
        continue;
      }
      if (c[i][j] != 'X') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
      if (!dp[i][j]) p[i][j]++;
    }
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int sm = p[n][y];
    sm -= p[n][x];
    sm -= p[1][y];
    sm += p[1][x];
    if (!sm)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
