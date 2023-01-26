#include <bits/stdc++.h>
using namespace std;
int board[1009][1009];
int n, m;
bool vis[1009][1009];
enum cardinals { west, south, east, north };
int dfs(int x, int y) {
  vis[x][y] = 1;
  int size = 1;
  if (x - 1 >= 0 && !((board[x - 1][y] >> south) & 1) &&
      !((board[x - 1][y] >> north) & 1) && !vis[x - 1][y])
    size += dfs(x - 1, y);
  if (y - 1 >= 0 && !((board[x][y - 1] >> west) & 1) &&
      !((board[x][y] >> east) & 1) && !vis[x][y - 1])
    size += dfs(x, y - 1);
  if (x + 1 < n && !((board[x + 1][y] >> north) & 1) &&
      !((board[x][y] >> south) & 1) && !vis[x + 1][y])
    size += dfs(x + 1, y);
  if (y + 1 < m && !((board[x][y + 1] >> east) & 1) &&
      !((board[x][y] >> west) & 1) && !vis[x][y + 1])
    size += dfs(x, y + 1);
  return size;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> board[i][j];
  memset(vis, 0, sizeof vis);
  vector<int> ans;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) {
      if (!vis[i][j]) ans.push_back(dfs(i, j));
    }
  sort((ans).begin(), (ans).end(), greater<int>());
  for (auto i : ans) cout << i << ' ';
  cout << endl;
  return 0;
}
