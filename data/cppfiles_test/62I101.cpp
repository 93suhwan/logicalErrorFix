#include <bits/stdc++.h>
using namespace std;
int q, n, m;
struct node {
  int x, y;
};
queue<node> Q;
int a[1005][1005];
int vis[1005][1005];
int use, nuse;
int dp[1005][1005][2];
int bfs(int x, int y, int op, int z) {
  int qwq = 0;
  Q.push({x, y});
  while (Q.size()) {
    node v = Q.front();
    Q.pop();
    if (op) {
      v.x += z;
      op ^= 1;
    } else {
      v.y += z;
      op ^= 1;
    }
    if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m) {
      if (!vis[v.x][v.y]) {
        qwq++;
      }
      Q.push({v.x, v.y});
    }
  }
  return qwq;
}
int main() {
  long long ans = 0;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j][0] = dp[i][j][1] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j][0] += dp[i][j - 1][1];
      dp[i][j][1] += dp[i - 1][j][0];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j][0]--;
      dp[i][j][1]--;
      ans += dp[i][j][0] + dp[i][j][1] + 1;
    }
  }
  int x, y;
  long long now = ans;
  while (q--) {
    scanf("%d%d", &x, &y);
    int a1 = bfs(x, y, 0, 1);
    int a2 = bfs(x, y, 1, 1);
    int b1 = bfs(x, y, 0, -1);
    int b2 = bfs(x, y, 1, -1);
    if (!vis[x][y]) {
      now -= ((a1 * b2) + (a2 * b1) + a1 + b1 + a2 + b2);
      now--;
      vis[x][y] = 1;
      printf("%lld\n", now);
    } else {
      now += (a1 * b2) + (a2 * b1) + a1 + b1 + a2 + b2;
      now++;
      vis[x][y] = 0;
      printf("%lld\n", now);
    }
  }
  return 0;
}
