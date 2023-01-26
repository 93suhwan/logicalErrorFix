#include <bits/stdc++.h>
using namespace std;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], str[64];
int l = SIZE, r = SIZE;
int read(char *s) {
  while (r) {
    for (; l < r && buf[l] <= ' '; l++)
      ;
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  int cur = 0;
  while (r) {
    for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  s[cur] = '\0';
  return cur;
}
template <typename type>
bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  if (flag) x = -x;
  return true;
}
template <typename type>
type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  return flag ? -x : x;
}
}  // namespace FastIO
using FastIO::read;
const int N = 2e3 + 10;
struct node {
  int x, y;
};
char s[N][N];
int dp[N][N], idx[N], cnt[N][N], pre[N][N][2];
bool vis[N][N];
int tx[] = {1, -1, 0, 0};
int ty[] = {0, 0, 1, -1};
int main() {
  idx['U'] = 1;
  idx['D'] = 0;
  idx['L'] = 3;
  idx['R'] = 2;
  int t;
  read(t);
  while (t--) {
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; i++) {
      read(s[i] + 1);
      for (int j = 1; j <= m; j++)
        vis[i][j] = pre[i][j][0] = pre[i][j][1] = cnt[i][j] = dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int sx = i + tx[idx[s[i][j]]], sy = j + ty[idx[s[i][j]]];
        cnt[sx][sy]++;
      }
    }
    queue<node> Q;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (cnt[i][j] == 0) Q.push({i, j}), pre[i][j][0] = i, pre[i][j][1] = j;
      }
    }
    while (!Q.empty()) {
      node p = Q.front();
      Q.pop();
      int sx = p.x + tx[idx[s[p.x][p.y]]], sy = p.y + ty[idx[s[p.x][p.y]]];
      if (sx <= 0 || sx > n || sy <= 0 || sy > m) continue;
      cnt[sx][sy]--;
      if (dp[sx][sy] < dp[p.x][p.y] + 1)
        dp[sx][sy] = dp[p.x][p.y] + 1, pre[sx][sy][0] = pre[p.x][p.y][0],
        pre[sx][sy][1] = pre[p.x][p.y][1];
      if (cnt[sx][sy] == 0) Q.push({sx, sy});
    }
    int ans = 0, S, T;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (ans < dp[i][j] + 1) ans = dp[i][j] + 1, S = i, T = j;
        if (cnt[i][j] > 0 && !vis[i][j]) {
          int res = 0, Max = 0, ansx = 0, ansy = 0;
          int x = i, y = j;
          do {
            res++;
            if (Max < dp[x][y]) {
              Max = dp[x][y];
              ansx = x, ansy = y;
            }
            vis[x][y] = true;
            int sx = x + tx[idx[s[x][y]]];
            int sy = y + ty[idx[s[x][y]]];
            x = sx, y = sy;
          } while (x != i || y != j);
          if (!ansx) ansx = x, ansy = y;
          if (Max + res > ans) ans = Max + res, S = ansx, T = ansy;
        }
      }
    }
    if (pre[S][T][0]) {
      int i = S, j = T;
      S = pre[i][j][0], T = pre[i][j][1];
    }
    printf("%d %d %d\n", S, T, ans);
  }
  return 0;
}
