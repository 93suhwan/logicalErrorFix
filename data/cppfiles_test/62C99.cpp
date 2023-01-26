#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  int x = 1, s = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return x * s;
}
int M[1005][1005];
int main() {
  int n = read(), m = read(), q = read();
  int ans = n * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a = n - i, b = m - j;
      if (a > b)
        ans += b * 2 + 1;
      else
        ans += a * 2;
      if (b > a)
        ans += a * 2 + 1;
      else
        ans += b * 2;
    }
  }
  for (int i = 1; i <= q; i++) {
    int a = read(), b = read();
    int x = a, y = b, A = 0, B = 0, tmp = M[a][b];
    M[a][b] = 0;
    while (1) {
      if (x > 0 && y > 0 && M[x][y] == 0)
        A++, x--;
      else
        break;
      if (x > 0 && y > 0 && M[x][y] == 0)
        A++, y--;
      else
        break;
    }
    x = a, y = b;
    while (1) {
      if (x <= n && y <= m && M[x][y] == 0)
        B++, y++;
      else
        break;
      if (x <= n && y <= m && M[x][y] == 0)
        B++, x++;
      else
        break;
    }
    if (tmp)
      ans += A * B;
    else
      ans -= A * B;
    A = B = 0;
    x = a, y = b;
    while (1) {
      if (x > 0 && y > 0 && M[x][y] == 0)
        A++, y--;
      else
        break;
      if (x > 0 && y > 0 && M[x][y] == 0)
        A++, x--;
      else
        break;
    }
    x = a, y = b;
    while (1) {
      if (x <= n && y <= m && M[x][y] == 0)
        B++, x++;
      else
        break;
      if (x <= n && y <= m && M[x][y] == 0)
        B++, y++;
      else
        break;
    }
    if (tmp)
      ans += A * B - 1;
    else
      ans -= A * B - 1;
    printf("%d\n", ans);
    M[a][b] = tmp ^ 1;
  }
  return 0;
}
