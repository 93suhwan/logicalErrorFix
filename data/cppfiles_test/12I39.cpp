#include <bits/stdc++.h>
using namespace std;
char a[2333][2333];
struct node {
  int dis;
  int sx, sy, tx, ty;
};
vector<node> pq[8111111];
int dis[2333][2333];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= m; j++) {
      if (a[i][j] == '1') {
        pq[0].push_back((node){0, i, j, i, j});
        dis[i][j] = 0;
      }
    }
  }
  for (int minw = 0; minw <= n * n + m * m; minw++) {
    while (!pq[minw].empty()) {
      auto z = pq[minw].back();
      pq[minw].pop_back();
      if (dis[z.tx][z.ty] != z.dis) continue;
      for (int d = 0; d < 4; d++) {
        int x = z.tx + dx[d], y = z.ty + dy[d];
        if (0 <= x and x <= n and 0 <= y and y <= m) {
          if (dis[x][y] > (x - z.sx) * (x - z.sx) + (y - z.sy) * (y - z.sy)) {
            dis[x][y] = (x - z.sx) * (x - z.sx) + (y - z.sy) * (y - z.sy);
            pq[dis[x][y]].push_back((node){dis[x][y], z.sx, z.sy, x, y});
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      ans += dis[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}
