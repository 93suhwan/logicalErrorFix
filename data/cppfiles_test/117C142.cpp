#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long INF = 2e18;
struct pt {
  int x;
  int y;
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<vector<pt>>> adj(n, vector<vector<pt>>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> ct(n, vector<int>(m, 0));
    queue<pt> Q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c = grid[i][j];
        if (c == '#') continue;
        if (c == 'L') {
          Q.push({i, j});
          vis[i][j] = true;
        }
        for (int k = 0; k < 4; k++) {
          int xx = i + dx[k], yy = j + dy[k];
          if (xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] != '#') {
            ct[i][j]++;
            adj[i][j].push_back({xx, yy});
          }
        }
      }
    }
    while (!Q.empty()) {
      pt x = Q.front();
      Q.pop();
      for (pt curr : adj[x.x][x.y]) {
        ct[curr.x][curr.y]--;
        if (vis[curr.x][curr.y]) continue;
        if (ct[curr.x][curr.y] < 2) {
          vis[curr.x][curr.y] = true;
          Q.push(curr);
          grid[curr.x][curr.y] = '+';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
