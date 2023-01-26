#include <bits/stdc++.h>
using namespace std;
template <class T>
T ABS(T x) {
  return x < 0 ? -x : x;
}
long long read() {
  long long s = 0, w = 1;
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') w = -1;
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * w;
}
const long long maxn = 1e6 + 10;
string S[maxn], w;
char tmp[maxn];
long long v[maxn], dx[] = {0, 0, +1, -1}, dy[] = {+1, -1, 0, 0}, n, m;
bool onl(long long x, long long y) {
  long long tot = 0;
  for (long long i = 0; i < 4; i++) {
    long long nx = x + dx[i], ny = y + dy[i];
    if (nx && ny && nx <= n && ny <= m && S[nx][ny] != '#') {
      if (!v[(nx - 1) * m + ny]) ++tot;
    }
  }
  if (tot > 1) return 0;
  return 1;
}
void bfs(long long X, long long Y) {
  v[(X - 1) * m + Y] = 1;
  queue<pair<long long, long long> > Q;
  Q.push(make_pair(X, Y));
  while (!Q.empty()) {
    long long x = Q.front().first, y = Q.front().second;
    Q.pop();
    for (long long i = 0; i < 4; i++) {
      long long nx = x + dx[i], ny = y + dy[i];
      if (nx && ny && nx <= n && ny <= m && !v[(nx - 1) * m + ny] &&
          S[nx][ny] != '#' && onl(nx, ny))
        v[(nx - 1) * m + ny] = 1, Q.push(make_pair(nx, ny));
    }
  }
}
signed main() {
  long long csa = read();
  while (csa--) {
    n = read(), m = read();
    for (long long i = 1; i <= n; i++) scanf("%s", tmp), S[i] = " " + (w = tmp);
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++)
        if (S[i][j] == 'L') bfs(i, j);
    for (long long i = 1; i <= n; i++, cout << '\n')
      for (long long j = 1; j <= m; j++)
        if (S[i][j] == 'L')
          cout << 'L';
        else if (v[(i - 1) * m + j])
          cout << '+';
        else
          cout << S[i][j];
    for (long long i = 1; i <= n * m; i++) v[i] = 0;
  }
  return 0;
}
