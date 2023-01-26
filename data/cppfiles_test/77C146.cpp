#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
int g[N][N], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, n, m;
bool st[N][N];
vector<int> ans;
int bfs(int x, int y) {
  if (st[x][y]) return INF;
  queue<pair<int, int> > q;
  q.push({x, y});
  int ans = 1;
  st[x][y] = true;
  while (q.size()) {
    int a = q.front().first, b = q.front().second, val = g[a][b];
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (((val >> i) & 1) == 0) {
        int c = a + dx[i], d = b + dy[i];
        if (c < 0 || c >= n || d < 0 || d >= m || st[c][d]) continue;
        q.push({c, d});
        st[c][d] = true;
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  memset(st, 0, sizeof st);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t = bfs(i, j);
      if (t != INF) ans.push_back(t);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
  return 0;
}
