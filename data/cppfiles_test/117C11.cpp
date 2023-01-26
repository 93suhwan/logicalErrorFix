#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int sx, sy;
char grid[1000005];
bool blocked(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m || grid[x * m + y] == '#';
}
bool justify(int cx, int cy) {
  if (blocked(cx, cy)) {
    return false;
  }
  if (grid[cx * m + cy] == '+') {
    return false;
  }
  int free = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = cx + dx[i], ny = cy + dy[i];
    if (!blocked(nx, ny) && grid[nx * m + ny] == '.') {
      ++free;
    }
  }
  return free <= 1;
}
void bfs(int sx, int sy) {
  queue<pair<int, int>> ts;
  grid[sx * m + sy] = '+';
  ts.emplace(sx, sy);
  while (!ts.empty()) {
    pair<int, int> tp = ts.front();
    ts.pop();
    int cx = tp.first, cy = tp.second;
    for (int i = 0; i < 4; ++i) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (justify(nx, ny)) {
        ts.emplace(nx, ny);
        grid[nx * m + ny] = '+';
      }
    }
  }
}
void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i * m + j] == 'L') {
        sx = i;
        sy = j;
        break;
      }
    }
  }
  bfs(sx, sy);
  grid[sx * m + sy] = 'L';
  for (int i = 0; i < n; ++i) {
    char tmp = grid[(i + 1) * m];
    grid[(i + 1) * m] = 0;
    cout << &grid[i * m] << '\n';
    grid[(i + 1) * m] = tmp;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> &grid[i * m];
    }
    solve();
  }
}
