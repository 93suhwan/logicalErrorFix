#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, m, i, j, k, q;
long long ans, x, y;
long long a[1010][1010];
long long u1, u2, v1, v2;
signed main() {
  n = read();
  m = read();
  q = read();
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) ans += (min(i - 1, j - 1) * 4 + 1 + (i != j));
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) a[i][j] = 1;
  for (i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = -1;
  for (i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = -1;
  while (q--) {
    x = read();
    y = read();
    a[x][y] = -a[x][y];
    ans += a[x][y];
    u1 = v1 = 0;
    u2 = v2 = 0;
    for (i = x, j = y;;) {
      --i;
      if (a[i][j] == -1) break;
      ++u1;
      --j;
      if (a[i][j] == -1) break;
      ++u1;
    }
    for (i = x, j = y;;) {
      --j;
      if (a[i][j] == -1) break;
      ++u2;
      --i;
      if (a[i][j] == -1) break;
      ++u2;
    }
    for (i = x, j = y;;) {
      ++i;
      if (a[i][j] == -1) break;
      ++v1;
      ++j;
      if (a[i][j] == -1) break;
      ++v1;
    }
    for (i = x, j = y;;) {
      ++j;
      if (a[i][j] == -1) break;
      ++v2;
      ++i;
      if (a[i][j] == -1) break;
      ++v2;
    }
    ans += a[x][y] * (u1 + v1 + u2 + v2 + u1 * v2 + u2 * v1);
    printf("%lld\n", ans);
  }
  return 0;
}
