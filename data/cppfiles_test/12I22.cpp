#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int MOV[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node {
  int x, y, dis, xf, yf;
  bool operator<(const node &b) const { return dis > b.dis; }
};
int n, m;
char ch[N];
int dis[N][N];
int D(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
  scanf("%d%d", &n, &m);
  n++, m++;
  priority_queue<node> qu;
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; j++)
      if (ch[j] == '1') qu.push({i, j, 0, i, j}), dis[i][j] = 0;
  }
  while (!qu.empty()) {
    node f = qu.top();
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int newx = f.x + MOV[i][0], newy = f.y + MOV[i][1];
      if (newx < 1 || newx > n || newy < 1 || newy > m) continue;
      if (dis[newx][newy] > D(newx, newy, f.xf, f.yf)) {
        dis[newx][newy] = D(newx, newy, f.xf, f.yf);
        qu.push({newx, newy, dis[newx][newy], f.xf, f.yf});
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += dis[i][j];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
