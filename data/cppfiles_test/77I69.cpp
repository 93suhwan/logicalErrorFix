#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int bfs(vector<vector<bool>>& grid, int x1, int y1) {
  queue<pair<int, int>> q;
  q.push({x1, y1});
  grid[x1][y1] = true;
  vector<pair<int, int>> dim = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int ans = 1;
  while (!q.empty()) {
    int tx = q.front().first, ty = q.front().second;
    q.pop();
    for (auto pr : dim) {
      int u1 = tx + pr.first, u2 = ty + pr.second;
      if (0 <= u1 and u1 < grid.size() and 0 <= u2 and u2 < grid[0].size() and
          !grid[u1][u2]) {
        q.push({u1, u2});
        grid[u1][u2] = true;
        ++ans;
      }
    }
  }
  return (ans + 1) / 2;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> grid(n * 2 + 1, vector<bool>(m * 2 + 1, true));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int gx = 2 * i + 1, gy = 2 * j + 1;
      grid[gx][gy] = false;
      int x;
      cin >> x;
      for (int k = 0; k < 4; ++k) {
        if (!(x & (1 << k))) {
          if (k == 3) {
            grid[gx - 1][gy] = false;
          } else if (k == 2) {
            grid[gx][gy + 1] = false;
          } else if (k == 1) {
            grid[gx + 1][gy] = false;
          } else {
            grid[gx][gy - 1] = false;
          }
        }
      }
    }
  }
  for (auto i : grid) {
    for (auto j : i) cout << j;
    cout << "\n";
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!grid[i * 2 + 1][j * 2 + 1]) {
        ans.push_back(bfs(grid, i * 2 + 1, j * 2 + 1));
      }
    }
  }
  sort((ans).begin(), (ans).end(), greater<int>());
  for (int i : ans) {
    cout << i << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
