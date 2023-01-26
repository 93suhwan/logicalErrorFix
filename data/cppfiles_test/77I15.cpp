#include <bits/stdc++.h>
using namespace std;
const int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int tile[n][m], vis[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &tile[i][j]);
  memset(vis, 0, sizeof vis);
  vector<int> ans;
  queue<pair<int, int> > q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!vis[i][j]) {
        q.push(pair<int, int>(i, j));
        vis[i][j] = 1;
        int cnt = 1;
        while (q.size()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          for (int i = 0; i < 4; ++i)
            if (!(tile[x][y] & (1 << i))) {
              int xx = x + dir[i][0], yy = y + dir[i][1];
              if (!vis[xx][yy]) {
                vis[xx][yy] = 1;
                q.push(pair<int, int>(xx, yy));
                ++cnt;
              }
            }
        }
        ans.push_back(cnt);
      }
  sort(ans.begin(), ans.end());
  do {
    printf("%d", ans.back());
    ans.pop_back();
    putchar(ans.empty() ? '\n' : ' ');
  } while (!ans.empty());
}
