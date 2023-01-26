#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
char* s[1000003];
bool chk(long long x, long long y) {
  if (s[x][y] != '.') return 0;
  long long A = 0;
  if (s[x - 1][y] == '.' || s[x - 1][y] == 'L' || s[x - 1][y] == '+') ++A;
  if (s[x + 1][y] == '.' || s[x + 1][y] == 'L' || s[x + 1][y] == '+') ++A;
  if (s[x][y - 1] == '.' || s[x][y - 1] == 'L' || s[x][y - 1] == '+') ++A;
  if (s[x][y + 1] == '.' || s[x][y + 1] == 'L' || s[x][y + 1] == '+') ++A;
  return A <= 2;
}
signed main() {
  for (long long T = read(); T--;) {
    long long n = read(), m = read();
    for (long long i = 0; i <= n + 1; ++i) s[i] = new char[m + 3];
    for (long long i = 0; i <= n + 1; ++i)
      for (long long j = 0; j <= m + 1; ++j) s[i][j] = 0;
    for (long long i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    queue<pair<long long, long long>> q;
    for (long long i = 1; i <= n; ++i)
      for (long long j = 1; j <= m; ++j)
        if (s[i][j] == 'L') q.push(make_pair(i, j));
    while (!q.empty()) {
      auto xx = q.front();
      q.pop();
      long long x = xx.first, y = xx.second;
      if (s[x][y] != 'L') s[x][y] = '+';
      if (chk(x - 1, y)) q.push(make_pair(x - 1, y));
      if (chk(x + 1, y)) q.push(make_pair(x + 1, y));
      if (chk(x, y - 1)) q.push(make_pair(x, y - 1));
      if (chk(x, y + 1)) q.push(make_pair(x, y + 1));
    }
    for (long long i = 1; i <= n; ++i, puts(""))
      for (long long j = 1; j <= m; ++j) putchar(s[i][j]);
    for (long long i = 0; i <= n + 1; ++i) delete s[i];
  }
  return 0;
}
