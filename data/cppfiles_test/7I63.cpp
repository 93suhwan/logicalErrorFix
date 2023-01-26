#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 105;
int n, m, a[N], b[N], INF;
char s[N];
inline void init() {
  n = read();
  m = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
  scanf("%s", s + 1);
  for (int i = 1; i <= m; i++) b[i] = s[i] - '0';
}
int nxt[N];
inline void kmp() {
  int j = 0;
  for (int i = 2; i <= m; i++) {
    while (j && b[j + 1] != b[i]) j = nxt[j];
    if (b[j + 1] == b[i]) j++;
    nxt[i] = j;
  }
}
int dp[N][N][N];
inline void upd(int &x, int y) { x = min(x, y); }
inline int getfail(int c, int now) {
  while (now && b[now + 1] != c) now = nxt[now];
  if (b[now + 1] == c) now++;
  return now;
}
inline void solve() {
  kmp();
  memset(dp, 127 / 3, sizeof dp);
  INF = dp[0][0][0];
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= n - m + 1; k++) {
        if (dp[i - 1][j][k] == INF) continue;
        int c = a[i], t = getfail(c, j), v = 0;
        if (t == m) t = nxt[t], v = 1;
        upd(dp[i][t][k + v], dp[i - 1][j][k]);
        c = a[i] ^ 1, t = getfail(c, j);
        v = 0;
        if (t == m) t = nxt[t], v = 1;
        upd(dp[i][t][k + v], dp[i - 1][j][k] + 1);
      }
    }
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int ans = INF;
    for (int j = 0; j <= m; j++) upd(ans, dp[n][j][i]);
    write((ans == INF) ? -1 : ans);
    putchar(' ');
  }
}
int main() {
  init();
  solve();
  return 0;
}
