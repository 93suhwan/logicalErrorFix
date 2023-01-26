#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
using namespace std;
bool ans;
void dfs(vector<string> &grid, int i, int j, vector<vector<int>> &vis) {
  if (i < 0 || i > 1 || j >= grid[0].size() || j < 0 || grid[i][j] == '1' ||
      vis[i][j] == 1 || ans == true)
    return;
  vis[i][j] = 1;
  if (i == 1 && j == grid[0].size() - 1) {
    ans = true;
    return;
  }
  int dx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
  int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
  for (int ii = 0; ii < 8; ii++) {
    int xx = i + dx[ii], yy = j + dy[ii];
    if (xx < 0 || xx > 1 || yy < 0 || yy >= grid[0].size() ||
        grid[xx][yy] == '1' || vis[xx][yy] == 1)
      continue;
    dfs(grid, xx, yy, vis);
  }
  return;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<int>> vis(2, vector<int>(n, 0));
  vector<string> grid;
  string s1, s2;
  cin >> s1 >> s2;
  grid.push_back(s1);
  grid.push_back(s2);
  ans = false;
  dfs(grid, 0, 0, vis);
  cout << (ans == true ? "YES" : "NO") << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
