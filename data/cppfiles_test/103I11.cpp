#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t, n, m, ans[2005][2005];
char s[N][N];
int dfs(int x, int y, int d) {
  if (ans[x][y] >= 0) return ans[x][y];
  int xx = x, yy = y;
  if (s[x][y] == 'L')
    y--;
  else if (s[x][y] == 'R')
    y++;
  else if (s[x][y] == 'U')
    x--;
  else
    x++;
  if (x < 1 || x > n || y < 1 || y > m) {
    ans[x][y] = 1;
    return 1;
  }
  ans[xx][yy] = -1;
  if (ans[x][y] == -1) {
    ans[xx][yy] = d + 1;
    return -1;
  }
  int tem = dfs(x, y, d + 1);
  if (tem >= 0)
    ans[xx][yy] = tem;
  else {
    ans[xx][yy] = ans[x][y];
    return -1;
  }
  return ans[xx][yy];
}
void slv() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ans[i][j] = -2;
    }
  }
  int ma = 0, x = 1, y = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dfs(i, j, 0);
      if (ans[x][y] > ma) {
        ma = ans[x][y];
        x = i;
        y = j;
      }
    }
  }
  printf("%d %d %d\n", x, y, ma);
}
int main() {
  {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
  }
  scanf("%d", &t);
  while (t--) slv();
}
