#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int t, n, m, ans[N][N], d[N][N], top, nx, ny, x, y;
pair<int, int> q[N * N];
char s[N][N];
void slv() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
    for (int j = 1; j <= m; ++j) ans[i][j] = 0, d[i][j] = 0;
  }
  int ma = 0, ax, ay;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!ans[i][j]) {
        top = 0;
        x = i, y = j;
        while (1) {
          q[++top] = {x, y};
          d[x][y] = top;
          nx = x;
          ny = y;
          if (s[x][y] == 'U')
            nx--;
          else if (s[x][y] == 'D')
            nx++;
          else if (s[x][y] == 'L')
            ny--;
          else
            ny++;
          if (nx < 1 || nx > n || ny < 1 || ny > m) {
            int num = 0;
            for (int k = top; k >= 1; --k) {
              ans[q[k].first][q[k].second] = ++num;
            }
            break;
          }
          if (ans[nx][ny]) {
            int num = ans[nx][ny];
            for (int k = top; k >= 1; --k) {
              ans[q[k].first][q[k].second] = ++num;
            }
            break;
          }
          if (d[nx][ny]) {
            int num = top - d[nx][ny] + 1;
            for (int k = d[nx][ny]; k <= top; ++k) {
              ans[q[k].first][q[k].second] = num;
            }
            for (int k = d[nx][ny] - 1; k >= 1; --k) {
              ans[q[k].first][q[k].second] = ++num;
            }
            break;
          }
          x = nx;
          y = ny;
        }
      }
      if (ans[i][j] > ma) {
        ma = ans[i][j];
        ax = i;
        ay = j;
      }
    }
  }
  printf("%d %d %d\n", ax, ay, ma);
}
int main() {
  scanf("%d", &t);
  while (t--) slv();
}
