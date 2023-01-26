#include <bits/stdc++.h>
using namespace std;
const long long N = 1000;
const long long M = 1e5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long read() {
  long long x = 0, y = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; y |= (ch == '-'), ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * (y ? -1 : 1);
}
long long a, b, c, s[N + 5][N + 5][2];
bool q[N + 5][N + 5];
signed main() {
  a = read();
  b = read();
  c = read();
  long long ans = 0, x, y;
  for (long long i = 1; i <= a; ++i)
    for (long long j = 1; j <= b; ++j) {
      if (i != 1) s[i][j][0] = s[i - 1][j][1] + 1;
      if (j != 1) s[i][j][1] = s[i][j - 1][0] + 1;
      q[i][j] = 0;
      ans += s[i][j][0] + s[i][j][1] + 1;
    }
  for (long long i = 1; i <= c; ++i) {
    x = read();
    y = read();
    if (!q[x][y]) {
      q[x][y] = 1;
      long long n = x, m = y + 1, tmp = s[x][y][0] + 1;
      ans -= tmp;
      for (long long i = 0; n <= a && m <= b && !q[n][m];
           n += (i ^ 1), m += (i & 1), i ^= 1)
        ans -= tmp, s[n][m][i ^ 1] -= tmp;
      n = x + 1, m = y, tmp = s[x][y][1] + 1;
      ans -= tmp - 1;
      for (long long i = 1; n <= a && m <= b && !q[n][m];
           n += (i ^ 1), m += (i & 1), i ^= 1)
        ans -= tmp, s[n][m][i ^ 1] -= tmp;
      s[x][y][0] = s[x][y][1] = 0;
    } else {
      q[x][y] = 0;
      long long n = x, m = y + 1, tmp = s[x - 1][y][1] + 1;
      if (x != 1 && !q[x - 1][y]) ++tmp;
      ans += tmp;
      for (long long i = 0; n <= a && m <= b && !q[n][m];
           n += (i ^ 1), m += (i & 1), i ^= 1)
        ans += tmp, s[n][m][i ^ 1] += tmp;
      n = x + 1, m = y, tmp = s[x][y - 1][0] + 1;
      if (y != 1 && !q[x][y - 1]) ++tmp;
      ans += tmp - 1;
      for (long long i = 1; n <= a && m <= b && !q[n][m];
           n += (i ^ 1), m += (i & 1), i ^= 1)
        ans += tmp, s[n][m][i ^ 1] += tmp;
      if (x != 1 && !q[x - 1][y]) s[x][y][0] = s[x - 1][y][1] + 1;
      if (y != 1 && !q[x][y - 1]) s[x][y][1] = s[x][y - 1][0] + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
