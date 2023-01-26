#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
int sta_x = 0, sta_y = 0;
int n, m;
struct note {
  int x;
  int y;
} sta;
int pmove[5][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void bfs(vector<vector<char>> &mm) {
  sta.x = sta_x, sta.y = sta_y;
  queue<note> alls;
  alls.push(sta);
  while (!alls.empty()) {
    note temp;
    temp = alls.front();
    alls.pop();
    for (int i = 0; i < 4; i++) {
      int dx = temp.x + pmove[i][0];
      int dy = temp.y + pmove[i][1];
      int cnt = 0;
      if (dx >= 0 && dx < n && dy >= 0 && dy < m && mm[dx][dy] == '.') {
        for (int j = 0; j < 4; j++) {
          int ddx = dx + pmove[j][0];
          int ddy = dy + pmove[j][1];
          if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && mm[ddx][ddy] == '.')
            cnt++;
        }
        if (cnt <= 1) {
          mm[dx][dy] = '+';
          note res;
          res.x = dx, res.y = dy;
          alls.push(res);
        }
      }
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    vector<vector<char>> mm(n + 5, vector<char>(m + 5));
    for (int i = 0; i < n; i++) {
      char str[maxn];
      scanf("%s", str);
      for (int j = 0; j < m; j++) {
        if (str[j] == 'L') sta_x = i, sta_y = j;
        mm[i][j] = str[j];
      }
    }
    bfs(mm);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << mm[i][j];
      cout << "\n";
    }
  }
  return 0;
}
