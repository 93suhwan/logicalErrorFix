#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x * f;
}
inline void write(register int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
int n, m;
int s[505], t[505], nxt[505], trans[505][2];
int f[2][505][505], ans[505];
void upd(int &x, int y) {
  if (x == -1) x = y;
  x = min(x, y);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    char ch = nc();
    while (ch != '0' && ch != '1') ch = nc();
    s[i] = ch - '0';
  }
  for (int i = 1; i <= m; ++i) {
    char ch = nc();
    while (ch != '0' && ch != '1') ch = nc();
    t[i] = ch - '0';
  }
  for (int i = 2, p = 0; i <= m; ++i) {
    while (p && t[p + 1] != t[i]) p = nxt[p];
    if (t[p + 1] == t[i]) ++p;
    nxt[i] = p;
  }
  trans[0][t[1]] = 1;
  for (int i = 1; i < m; ++i) {
    if (i < m - 1) trans[i][t[i + 1]] = i + 1;
    for (int j = 0; j <= 1; ++j)
      trans[i][j] = max(trans[i][j], trans[nxt[i]][j]);
  }
  int las = 0, cur = 1;
  memset(f[las], -1, sizeof(f[las]));
  f[las][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(f[cur], -1, sizeof(f[cur]));
    for (int j = 0; j < m; ++j)
      for (int k = 0; k <= n - m + 1; ++k)
        if (f[las][j][k] != -1) {
          for (int l = 0; l <= 1; ++l) {
            if (j == m - 1 && l == t[m])
              upd(f[cur][trans[j][l]][k + 1], f[las][j][k] + (s[i] != l));
            else
              upd(f[cur][trans[j][l]][k], f[las][j][k] + (s[i] != l));
          }
        }
    cur ^= 1, las ^= 1;
  }
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j <= n - m + 1; ++j)
      if (f[las][i][j] != -1) upd(ans[j], f[las][i][j]);
  for (int i = 0; i <= n - m + 1; ++i) printf("%d ", ans[i]);
  return 0;
}
