#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
char s[MAXN][MAXN];
int n, m;
int vis[MAXN][MAXN], ans[MAXN][MAXN], val[MAXN][MAXN];
int tg = INF;
bool ok = true;
void dfs(int x, int y) {
  int nx = x, ny = y;
  if (s[x][y] == 'D')
    nx++;
  else if (s[x][y] == 'U')
    nx--;
  else if (s[x][y] == 'L')
    ny--;
  else
    ny++;
  if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
    if ((s[x][y] == 'U' && s[nx][ny] == 'D') ||
        (s[x][y] == 'D' && s[nx][ny] == 'U') ||
        (s[x][y] == 'L' && s[nx][ny] == 'R') ||
        (s[x][y] == 'R' && s[nx][ny] == 'L'))
      ans[x][y] = 2;
    else {
      if (val[nx][ny] == INF) {
        ans[x][y] = ans[nx][ny] + 1;
        return;
      }
      if (!vis[nx][ny]) {
        vis[nx][ny] = 1;
        val[nx][ny] = val[x][y] + 1;
        dfs(nx, ny);
      }
      if (!ans[nx][ny]) {
        tg = val[nx][ny];
        ok = false;
        ans[x][y] = val[x][y] - val[nx][ny] + 1;
        return;
      }
      if (ok || val[x][y] < tg)
        ans[x][y] = ans[nx][ny] + 1;
      else {
        ans[x][y] = ans[nx][ny];
        val[x][y] = INF;
      }
    }
  } else
    ans[x][y] = 1;
  return;
}
signed main() {
  int t = read();
  while (t--) {
    n = read(), m = read();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) vis[i][j] = 0, ans[i][j] = 0, val[i][j] = 0;
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j]) {
          tg = INF;
          vis[i][j] = 1;
          ok = true;
          val[i][j] = 1;
          dfs(i, j);
        }
      }
    }
    int maxs = -1, mx = 0, my = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ans[i][j] > maxs) {
          maxs = ans[i][j];
          mx = i, my = j;
        }
      }
    }
    printf("%d %d %d\n", mx + 1, my + 1, maxs);
  }
  return 0;
}
