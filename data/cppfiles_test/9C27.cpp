#include <bits/stdc++.h>
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
const int N = 1e3 + 7;
int n, m, k, a[N][N];
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = read();
  while (k-- > 0) {
    int y = read(), x = 1, u;
    while (x <= n) {
      u = a[x][y];
      a[x][y] = 2;
      if (u == 1) ++y;
      if (u == 3) --y;
      if (u == 2) ++x;
    }
    printf("%d ", y);
  }
  return 0;
}
