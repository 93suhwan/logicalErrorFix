#include <bits/stdc++.h>
using namespace std;
int dic[2][4] = {{0, 1, 0, -1}, {-1, 0, 1, 0}};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> arr(n, vector<int>(m));
  vector<vector<int>> flag(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  queue<pair<int, int>> root;
  queue<pair<int, int>> op;
  int sum;
  vector<int> room;
  root.push({0, 0});
  while (!root.empty()) {
    sum = 0;
    if (flag[root.front().first][root.front().second] == 0) {
      op.push(root.front());
      sum++;
      flag[root.front().first][root.front().second] = 1;
      root.pop();
      while (!op.empty()) {
        int r = op.front().first, c = op.front().second;
        op.pop();
        for (int i = 0; i < 4; i++) {
          int nr = r + dic[0][i], nc = c + dic[1][i];
          if (0 <= nr && nr < n && 0 <= nc && nc < m) {
            if (!flag[nr][nc] && !(arr[r][c] & (1 << i))) {
              op.push({nr, nc});
              sum++;
              flag[nr][nc] = 1;
            } else if (i == 2 && arr[r][c] & (1 << i))
              root.push({nr, nc});
          }
        }
      }
      room.push_back(sum);
    } else
      root.pop();
  }
  sort(room.begin(), room.end());
  for (int i = room.size() - 1; i >= 0; i--) {
    printf("%d%c", room[i], i ? ' ' : '\n');
  }
  return 0;
}
