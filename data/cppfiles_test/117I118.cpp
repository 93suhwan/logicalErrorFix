#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> D = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool canMove(int fr, int fc, int tr, int tc, int R, int C,
             vector<vector<char>> &G) {
  auto isGood = [&](int r, int c) -> bool {
    return r >= 0 && r < R && c >= 0 && c < C && G[r][c] != '#';
  };
  if (!isGood(fr, fc)) return false;
  if (!isGood(tr, tc)) return false;
  int cnt = 0;
  for (auto [dr, dc] : D) {
    cnt += isGood(fr + dr, fc + dc);
  }
  return cnt <= 2;
}
void solve() {
  int R, C;
  cin >> R >> C;
  vector<vector<char>> G(R, vector<char>(C, '*'));
  vector<vector<bool>> V(R, vector<bool>(C, false));
  int lr, lc;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> G[r][c];
      if (G[r][c] == 'L') {
        lr = r;
        lc = c;
      }
    }
  }
  queue<pair<int, int>> Q;
  Q.push({lr, lc});
  while (!Q.empty()) {
    auto [r, c] = Q.front();
    Q.pop();
    for (auto [dr, dc] : D) {
      if (canMove(dr + r, dc + c, r, c, R, C, G) && !V[dr + r][dc + c]) {
        Q.push({dr + r, dc + c});
        V[dr + r][dc + c] = true;
        G[dr + r][dc + c] = '+';
      }
    }
  }
  G[lr][lc] = 'L';
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cout << G[r][c];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
