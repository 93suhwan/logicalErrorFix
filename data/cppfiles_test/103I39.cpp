#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char g[N][N];
pair<int, int> par[N][N];
int t, n, m, f[N][N], vis[N][N], h[N][N];
inline bool valid(int x, int y) {
  return x > 0 and y > 0 and x <= n and y <= m;
}
pair<int, int> apply(int x, int y, char c) {
  if (c == 'L') --y;
  if (c == 'R') ++y;
  if (c == 'U') --x;
  if (c == 'D') ++x;
  return make_pair(x, y);
}
void go(int x, int y, int far = 0) {
  vis[x][y] = 1, h[x][y] = far;
  auto [new_x, new_y] = apply(x, y, g[x][y]);
  if (valid(new_x, new_y)) {
    if (!vis[new_x][new_y]) {
      par[new_x][new_y] = make_pair(x, y);
      go(new_x, new_y, far + 1);
    } else if (vis[new_x][new_y] == 1) {
      int far = h[x][y] - h[new_x][new_y] + 1;
      pair<int, int> at = make_pair(x, y);
      while (at != make_pair(new_x, new_y)) {
        auto [at_x, at_y] = at;
        f[at_x][at_y] = far, at = par[at_x][at_y];
      }
      f[new_x][new_y] = far;
    }
  }
  vis[x][y] = 2;
}
int call(int x, int y) {
  if (f[x][y] != -1) return f[x][y];
  auto [new_x, new_y] = apply(x, y, g[x][y]);
  return f[x][y] = 1 + call(new_x, new_y);
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%s", g[i] + 1);
      for (int j = 1; j <= m; ++j) f[i][j] = -1, vis[i][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j)
        if (!vis[i][j]) go(i, j);
    }
    int best = -1, x, y;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int cur = call(i, j);
        if (cur > best) best = cur, x = i, y = j;
      }
    }
    printf("%d %d %d\n", x, y, best);
  }
  return 0;
}
