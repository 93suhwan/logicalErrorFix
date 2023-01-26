#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}
bool operator<(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first && a.second < b.second;
}
bool operator>=(pair<int, int> a, pair<int, int> b) {
  return a.first >= b.first && a.second >= b.second;
}
int steps(pair<int, int> cur, vector<vector<bool>> &board,
          vector<pair<int, int>> &dir, int p) {
  int ans = 0;
  pair<int, int> low = {0, 0}, high = {board.size(), board[0].size()};
  do {
    ++ans;
    cur = cur + dir[p];
    p = (p + 1) % dir.size();
  } while (cur >= low && cur < high && board[cur.first][cur.second]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  long long total = 0;
  vector<vector<bool>> board(n, vector<bool>(m, 1));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      total += min(i + 1, j) + min(i, j + 1) + 2 * min(i, j) + 1;
  vector<pair<int, int>> m1 = {{-1, 0}, {0, -1}};
  vector<pair<int, int>> m2 = {{0, 1}, {1, 0}};
  for (int x, y, aux = 0; q--; aux = 0) {
    cin >> x >> y, --x, --y;
    for (int k = 0; k < m1.size(); ++k)
      aux += steps({x, y}, board, m1, k) * steps({x, y}, board, m2, k);
    total += (board[x][y] ? -aux + 1 : aux - 1);
    board[x][y] = !board[x][y];
    cout << total << '\n';
  }
  return 0;
}
