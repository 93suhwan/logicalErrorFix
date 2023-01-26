#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010101;
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> h >> w;
    vector<string> grid(h);
    for (int y = 0; y < h; ++y) cin >> grid[y];
    int labx, laby;
    for (int x = 0; x < w; ++x) {
      for (int y = 0; y < h; ++y) {
        if (grid[y][x] == 'L') {
          labx = x;
          laby = y;
        }
      }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(labx, laby));
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      if (grid[y][x] == '+' || grid[y][x] == '-') continue;
      int pos = 0;
      for (auto dir : dirs) {
        int nx = x + dir.first;
        int ny = y + dir.second;
        if (nx < 0 || nx >= w) continue;
        if (ny < 0 || ny >= h) continue;
        if (grid[ny][nx] != '#') ++pos;
      }
      if (pos <= 2) {
        if (grid[y][x] != 'L') grid[y][x] = '+';
        for (auto dir : dirs) {
          int nx = x + dir.first;
          int ny = y + dir.second;
          if (nx < 0 || nx >= w) continue;
          if (ny < 0 || ny >= h) continue;
          if (grid[ny][nx] == '.') q.push({nx, ny});
        }
      } else {
        if (grid[y][x] != 'L') grid[y][x] = '-';
      }
    }
    for (int y = 0; y < h; ++y) {
      for (char c : grid[y]) {
        if (c == '-')
          cout << '.';
        else
          cout << c;
      }
      cout << '\n';
    }
  }
}
