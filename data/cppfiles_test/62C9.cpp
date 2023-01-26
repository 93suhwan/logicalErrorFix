#include <bits/stdc++.h>
namespace wxy {
const long long N = 2e3 + 50;
long long f[N][N][2];
long long ans;
bool vis[N][N];
long long n, m, q, cnt;
inline void upd(long long x, long long y, long long t) {
  if (vis[x][y]) return;
  if (t == 0) {
    long long val = f[x + 1][y][1] + 1;
    ans += val - f[x][y][t];
    f[x][y][t] = val;
    if (y - 1 > 0) upd(x, y - 1, 1);
  } else {
    long long val = f[x][y + 1][0] + 1;
    ans += val - f[x][y][t];
    f[x][y][t] = val;
    if (x - 1 > 0) upd(x - 1, y, 0);
  }
}
inline void erase(long long x, long long y) {
  ans -= f[x][y][1] + f[x][y][0];
  f[x][y][1] = f[x][y][0] = 0;
  vis[x][y] = true;
  if (x - 1 > 0) upd(x - 1, y, 0);
  if (y - 1 > 0) upd(x, y - 1, 1);
  --cnt;
}
inline void insert(long long x, long long y) {
  vis[x][y] = false;
  upd(x, y, 1);
  upd(x, y, 0);
  ++cnt;
}
inline long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
inline void main() {
  n = read();
  m = read();
  q = read();
  for (long long i = n; i >= 1; i--)
    for (long long j = m; j >= 1; j--) {
      f[i][j][0] = f[i + 1][j][1] + 1;
      f[i][j][1] = f[i][j + 1][0] + 1;
      ans += f[i][j][0] + f[i][j][1];
    }
  cnt = n * m;
  while (q--) {
    long long a, b;
    a = read();
    b = read();
    if (vis[a][b])
      insert(a, b);
    else
      erase(a, b);
    printf("%lld\n", ans - cnt);
  }
}
}  // namespace wxy
signed main() {
  wxy::main();
  return 0;
}
