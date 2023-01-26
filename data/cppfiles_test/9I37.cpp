#include <bits/stdc++.h>
using namespace std;
char _buf[100000], *_p1 = _buf, *_p2 = _buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
const int maxn = 1005;
int a[maxn][maxn], n, m, k;
int c[maxn];
int fa[maxn][maxn];
inline int get(int *fa, int x) {
  if (x == fa[x]) return x;
  return fa[x] = get(fa, fa[x]);
}
inline void init() {}
inline void input() {
  n = gi(), m = gi(), k = gi();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = gi();
}
inline int go(int y) {
  int x = 1;
  while (x <= n) {
    x = get(fa[y], x);
    if (x != n) fa[y][x] = get(fa[y], fa[y][x + 1]);
    if (a[x][y] == 1)
      a[x][y] = 2, y++;
    else if (a[x][y] == 2)
      a[x][y] = 2, x++;
    else if (a[x][y] == 3)
      a[x][y] = 2, y--;
  }
  return y;
}
inline void solve() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) fa[j][i] = i;
  for (int i = 1; i <= k; ++i) {
    c[i] = gi();
    printf("%d ", go(c[i]));
  }
}
int main() {
  int T = 1;
  while (T--) {
    init();
    input();
    solve();
  }
  return 0;
}
