#include <bits/stdc++.h>
using namespace std;
int n, m, jv[1005][1005], mp[5005][5005], x, y, tot;
bool vis[5005][5005];
int ans[1000005];
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, 1, 0, -1};
inline bool cmp(int a, int b) { return a > b; }
inline int bfs(int x, int y) {
  int temp = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    pair<int, int> dmf = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = dmf.first + dx[i];
      int yy = dmf.second + dy[i];
      if (xx <= 0 || xx > n || yy <= 0 || yy > m || vis[xx][yy]) continue;
      if ((i == 0) &&
          (jv[xx][yy] == 2 || jv[xx][yy] == 3 || jv[xx][yy] == 6 ||
           jv[xx][yy] == 7 || jv[xx][yy] == 10 || jv[xx][yy] == 11 ||
           jv[xx][yy] == 14 || jv[xx][yy] == 15))
        continue;
      if ((i == 1) && (jv[xx][yy] == 1 || jv[xx][yy] == 3 || jv[xx][yy] == 5 ||
                       jv[xx][yy] == 7 || jv[xx][yy] == 9 || jv[xx][yy] == 11 ||
                       jv[xx][yy] == 13 || jv[xx][yy] == 15))
        continue;
      if ((i == 2) && jv[xx][yy] >= 8) continue;
      if ((i == 3) &&
          (jv[xx][yy] == 4 || jv[xx][yy] == 5 || jv[xx][yy] == 6 ||
           jv[xx][yy] == 7 || jv[xx][yy] == 12 || jv[xx][yy] == 13 ||
           jv[xx][yy] == 14 || jv[xx][yy] == 15))
        continue;
      temp++;
      vis[xx][yy] = 1;
      q.push(make_pair(xx, yy));
    }
  }
  return temp;
}
int main() {
  tot = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &jv[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        vis[i][j] = 1;
        ++tot;
        ans[tot] = bfs(i, j);
      }
    }
  }
  sort(ans + 1, ans + tot + 1, cmp);
  for (int i = 1; i < tot; i++) printf("%d ", ans[i]);
  printf("%d", ans[tot]);
  return 0;
}
