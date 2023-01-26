#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
queue<node> q;
vector<int> ans;
int a[1010][1010];
int vis[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n, m;
void bfs(int i, int j) {
  node u;
  u.x = i;
  u.y = j;
  q.push(u);
  int cnt = 1;
  vis[i][j] = 1;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    int flag = a[u.x][u.y];
    int fl[4] = {1, 1, 1, 1};
    for (int i = 0; i < 4; i++) {
      if (flag & 1) {
        fl[i] = 0;
      }
      flag >>= 1;
    }
    for (int i = 0; i < 4; i++) {
      if (fl[i]) {
        int x1 = u.x + dx[i];
        int y1 = u.y + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !vis[x1][y1]) {
          vis[x1][y1] = 1;
          node u1;
          u1.x = x1;
          u1.y = y1;
          q.push(u1);
          cnt++;
        }
      }
    }
  }
  ans.push_back(cnt);
}
bool cmp(int x, int y) { return x > y; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        bfs(i, j);
      }
    }
  }
  sort(ans.begin(), ans.end(), cmp);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
