#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> a(n, std::vector<char>(m));
    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a[i][j];
        if (a[i][j] == 'L') {
          que.emplace(i, j);
        }
      }
    }
    std::vector<int> dx{0, 0, -1, 1};
    std::vector<int> dy{-1, 1, 0, 0};
    while (!que.empty()) {
      int x = que.front().first;
      int y = que.front().second;
      que.pop();
      for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
          int nx = nextX + dx[j];
          int ny = nextY + dy[j];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '.') {
            cnt++;
          }
        }
        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m &&
            a[nextX][nextY] == '.' && cnt <= 1) {
          a[nextX][nextY] = '+';
          que.emplace(nextX, nextY);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << a[i][j];
      }
      std::cout << '\n';
    }
  }
  return 0;
}
