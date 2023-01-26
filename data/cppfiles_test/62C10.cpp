#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
long long down[N][N], rit[N][N], ans;
int flag[N][N], n, m;
void fun(int x, int y, int f) {
  int a = x, b = y;
  int xia, zuo;
  if (f == -1) {
    xia = rit[a][b] + 1;
    zuo = down[a][b] + 1;
    xia = xia * f;
    zuo = zuo * f;
    ans--;
    ans = ans - rit[a][b] - down[a][b];
    rit[a][b] = down[a][b] = 0;
  } else if (f == 1) {
    ans++;
    rit[a][b] = down[a][b + 1] + (flag[a][b + 1] != 1 && (b + 1 <= m));
    down[a][b] = rit[a + 1][b] + (flag[a + 1][b] != 1 && (a + 1 <= n));
    ans = ans + rit[a][b] + down[a][b];
    xia = rit[a][b] + 1;
    zuo = down[a][b] + 1;
  }
  int now = 0;
  while (1) {
    if (now == 0) {
      a = a - 1;
      if (a < 1 || flag[a][b] == 1) break;
      down[a][b] = down[a][b] + xia;
      ans = ans + xia;
    } else {
      b = b - 1;
      if (b < 1 || flag[a][b] == 1) break;
      rit[a][b] = rit[a][b] + xia;
      ans = ans + xia;
    }
    now = now ^ 1;
  }
  now = 1;
  a = x;
  b = y;
  while (1) {
    if (now == 0) {
      a = a - 1;
      if (a < 1 || flag[a][b] == 1) break;
      down[a][b] = down[a][b] + zuo;
      ans = ans + zuo;
    } else {
      b = b - 1;
      if (b < 1 || flag[a][b] == 1) break;
      rit[a][b] = rit[a][b] + zuo;
      ans = ans + zuo;
    }
    now = now ^ 1;
  }
  printf("%lld\n", ans);
}
void solve() {
  int i, j, q, x, y;
  scanf("%d%d%d", &n, &m, &q);
  for (i = n; i >= 1; --i) {
    for (j = m; j >= 1; --j) {
      if (i == n)
        down[i][j] == 0;
      else
        down[i][j] = down[i][j] + 1 + rit[i + 1][j];
      if (j == m)
        rit[i][j] == 0;
      else
        rit[i][j] = rit[i][j] + 1 + down[i][j + 1];
    }
  }
  ans = 0;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      ans = ans + down[i][j] + rit[i][j];
    }
  }
  ans = ans + n * m;
  for (i = 1; i <= q; ++i) {
    scanf("%d%d", &x, &y);
    if (flag[x][y] == 1) {
      flag[x][y] = 0;
      fun(x, y, 1);
    } else {
      flag[x][y] = 1;
      fun(x, y, -1);
    }
  }
  return;
}
int main() { solve(); }
