#include <bits/stdc++.h>
using namespace std;
vector<string> v(2005);
int n, m;
int dp[2005][2005], vis[2005][2005], x = 1, cir;
int solve(int r, int c) {
  if (r < 0 || c < 0 || r >= n || c >= m) return 0;
  if (dp[r][c] != -1) return dp[r][c];
  if (dp[r][c] == -1 && vis[r][c]) {
    cir = vis[r][c];
    return x - vis[r][c] - 1;
  }
  vis[r][c] = x++;
  if (v[r][c] == 'D')
    dp[r][c] = 1 + solve(r + 1, c);
  else if (v[r][c] == 'U')
    dp[r][c] = 1 + solve(r - 1, c);
  else if (v[r][c] == 'R')
    dp[r][c] = 1 + solve(r, c + 1);
  else
    dp[r][c] = 1 + solve(r, c - 1);
  if (cir == vis[r][c]) cir = 0;
  if (cir)
    return dp[r][c] - 1;
  else
    return dp[r][c];
}
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d, f, gg = 0, i, j, t, mod = 1e9 + 7, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= m; j++) {
        dp[i][j] = -1;
        vis[i][j] = 0;
      }
    }
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    f = -1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cir = 0;
        if (dp[i][j] == -1) solve(i, j);
        if (dp[i][j] > f) {
          f = dp[i][j];
          x = i + 1;
          y = j + 1;
        }
      }
    }
    cout << x << ' ' << y << ' ' << f << '\n';
  }
  return 0;
}
