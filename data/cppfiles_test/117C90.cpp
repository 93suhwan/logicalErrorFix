#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (auto& row : board) {
      cin >> row;
    }
    auto nei = [&](int i, int j) -> vector<pair<int, int>> {
      return {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    };
    auto valid = [&](int i, int j) -> bool {
      return 0 <= i && i < n && 0 <= j && j < m && board[i][j] == '.';
    };
    deque<pair<int, int>> bfs;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'L') {
          bfs.emplace_back(i, j);
        }
      }
    }
    while (!bfs.empty()) {
      auto [i, j] = bfs.front();
      bfs.pop_front();
      int cnt = 0;
      for (auto [ni, nj] : nei(i, j)) {
        if (valid(ni, nj)) {
          ++cnt;
        }
      }
      if (board[i][j] != '+' && (cnt <= 1 || board[i][j] == 'L')) {
        if (board[i][j] != 'L') {
          board[i][j] = '+';
        }
        for (auto [ni, nj] : nei(i, j)) {
          if (valid(ni, nj)) {
            bfs.emplace_back(ni, nj);
          }
        }
      }
    }
    for (auto row : board) {
      cout << row << "\n";
    }
  }
  return 0;
}
