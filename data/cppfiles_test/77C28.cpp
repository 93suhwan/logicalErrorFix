#include <bits/stdc++.h>
using namespace std;
int n, m, mp[1010][1010], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
vector<int> ans;
bool vis[1010][1010];
int bfs(int x, int y) {
  queue<pair<int, int> > q;
  q.push(make_pair(x, y)), vis[x][y] = true;
  int siz = 1;
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
      if (!((mp[t.first][t.second] >> i) & 1)) {
        int nx = t.first + dx[i], ny = t.second + dy[i];
        if (!vis[nx][ny]) q.push(make_pair(nx, ny)), vis[nx][ny] = true, siz++;
      }
  }
  return siz;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &mp[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!vis[i][j]) ans.push_back(bfs(i, j));
  sort(ans.begin(), ans.end(), greater<int>());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
