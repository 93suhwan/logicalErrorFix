#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long mod = 998244353;
int dfs(vector<string>& a, vector<vector<int>>& dp, int x, int y,
        vector<vector<bool>> visited) {
  if (x < 0 || x >= a.size()) return 0;
  if (y < 0 || y >= a[0].size()) return 0;
  if (visited[x][y]) return 0;
  if (dp[x][y]) return dp[x][y];
  int xx = x, yy = y;
  visited[x][y] = true;
  if (a[x][y] == 'D')
    x++;
  else if (a[x][y] == 'U')
    x--;
  else if (a[x][y] == 'L')
    y--;
  else
    y++;
  if (x >= 0 && x < a.size() && y >= 0 && y < a[0].size() && visited[x][y])
    dp[xx][yy] = 1;
  int ans = 1 + dfs(a, dp, x, y, visited);
  dp[xx][yy] += ans;
  return ans;
}
void solve(int cases) {
  long long n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> dp(n, vector<int>(m, 0));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  int ans = 0;
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int temp = dfs(a, dp, i, j, visited);
      if (ans < temp) {
        ans = temp;
        x = i, y = j;
      }
    }
  }
  cout << x + 1 << " " << y + 1 << " " << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  int cases = 1;
  while (tt--) {
    solve(cases);
    cases++;
  }
  return 0;
}
