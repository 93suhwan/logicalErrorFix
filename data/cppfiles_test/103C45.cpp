#include <bits/stdc++.h>
using namespace std;
char str[2020][2020];
int fusnfe[2020][2020];
int vis[2020][2020];
int ret[2020][2020];
int ans[2020][2020];
int cur = 0;
int n, m;
int cyc = 0;
pair<int, int> beg;
int dfs(int x, int y, int t = 0) {
  ("dfs %d %d %d\n", x, y, t);
  if (x < 0 || x == n || y < 0 || y == m) return 0;
  if (vis[x][y] == cur && ret[x][y] < cur) {
    cyc = 1;
    beg = {x, y};
    return ans[x][y] = t - fusnfe[x][y];
  }
  if (vis[x][y] == cur) return ans[x][y];
  vis[x][y] = cur;
  fusnfe[x][y] = t;
  int gox = x, goy = y;
  if (str[x][y] == 'R') goy++;
  if (str[x][y] == 'L') goy--;
  if (str[x][y] == 'U') gox--;
  if (str[x][y] == 'D') gox++;
  int r = dfs(gox, goy, t + 1);
  if (cyc) {
    if (pair<int, int>{x, y} == beg) cyc = 0;
    ans[x][y] = r;
  } else
    ans[x][y] = r + 1;
  ("ans %d %d = %d cyc %d\n", x, y, ans[x][y], cyc);
  ret[x][y] = cur;
  return ans[x][y];
}
int main() {
  int nt;
  scanf("%d", &nt);
  while (nt--) {
    cur++;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) vis[i][j] = 0;
    for (int i = 0; i < n; i++) scanf(" %s", str[i]);
    int mx = 0, ansx = 0, ansy = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (vis[i][j]) continue;
        int t = dfs(i, j);
        if (t > mx) {
          mx = t;
          ansx = i + 1;
          ansy = j + 1;
        }
      }
    printf("%d %d %d\n", ansx, ansy, mx);
  }
}
