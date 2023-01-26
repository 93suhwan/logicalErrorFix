#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve() {
  int n, m;
  cin >> n >> m;
  char mat[n][m];
  int notSure[n][m];
  int vis[n][m];
  pair<int, int> start;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      notSure[i][j] = 0;
      vis[i][j] = 0;
      if (mat[i][j] == 'L') start = {i, j};
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < 4; k++) {
        int r = i + dx[k], c = j + dy[k];
        if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] != '#')
          notSure[i][j]++;
      }
  vis[start.first][start.second] = 1;
  queue<pair<int, int>> Q;
  Q.push(start);
  while (!Q.empty()) {
    pair<int, int> curr = Q.front();
    Q.pop();
    for (int k = 0; k < 4; k++) {
      int r = curr.first + dx[k], c = curr.second + dy[k];
      if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] != '#' &&
          !vis[r][c]) {
        notSure[r][c]--;
        if (notSure[r][c] <= 1) {
          vis[r][c] = 1;
          mat[r][c] = '+';
          Q.push({r, c});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << mat[i][j];
    cout << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
