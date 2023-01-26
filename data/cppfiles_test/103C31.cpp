#include <bits/stdc++.h>
const long long N = 1e6 + 7, mod = 998244353, iz = 1 < 21, oz = 1 << 22;
typedef long long aN[N];
char is[iz], *i1 = is, *i2 = is, os[oz], *o1 = os, *o2 = os + oz;
int fgc() {
  return i1 == i2 && is == (i2 = is + fread(i1 = is, 1, iz, stdin)) ? -1
                                                                    : *i1++;
}
void fout() { fwrite(os, o1 - os, 1, stdout), o1 = os; }
int fpc(int c) {
  if (o1 == o2) fout();
  return *o1++ = c;
}
int (*gc)() = getchar, (*pc)(int) = putchar, wt[126];
int readchar(int l = 33, int r = 126) {
  if (l > r) std::swap(l, r);
  int c = gc();
  for (; c < l || c > r; c = gc())
    ;
  return c;
}
long long readll() {
  long long x = 0, w = 1;
  int c = gc();
  for (; c < 48 || c > 57; c = gc()) c - 45 || (w = -w);
  for (; c > 47 && c < 58; c = gc()) x = x * 10 + c - 48;
  return x * w;
}
void writell(long long u, int c = 32) {
  int t = 0;
  for (register unsigned long long n = u < 0 ? pc(45), 0ull - u : u; n; n /= 10)
    wt[++t] = n % 10 ^ 48;
  for (t || pc(48); t;) pc(wt[t--]);
  c&& pc(c);
}
int mygets(char* s, int c = 0) {
  char* t = s + 1;
  while ((*s = gc()) < 3)
    ;
  while ((*t = gc()) > 32) t++;
  c && (*t++ = c), *t = 0;
  return t - s;
}
int myputs(const char* s, int c = 10) {
  const char* t = s;
  while (*t) pc(*t++);
  c&& pc(c);
  return t - s + (c != 0);
}
char s[2003][2003];
int len[2003][2003];
void getnx(long long& x, long long& y) {
  switch (s[x][y]) {
    case 'U':
      x--;
      break;
    case 'L':
      y--;
      break;
    case 'D':
      x++;
      break;
    case 'R':
      y++;
      break;
  }
}
void calc() {
  long long n = readll(), m = readll(), ansl = 0, ansx = 0, ansy = 0;
  for (register long long i = 1; i <= n; i++) mygets(s[i] + 1);
  for (register long long i = 0; i <= n + 1; i++)
    memset(len[i], 0, (m + 2) << 2);
  for (register long long i = 1; i <= n; i++)
    for (register long long j = 1; j <= m; j++) {
      if (len[i][j]) continue;
      long long x = i, y = j, cnt = 0;
      while (x >= 1 && x <= n && y >= 1 && y <= m && !len[x][y])
        len[x][y] = -++cnt, getnx(x, y);
      cnt += std::max(len[x][y], 0) + 1;
      const long long nx = x, ny = y;
      x = i, y = j;
      while (x != nx || y != ny) len[x][y] += cnt, getnx(x, y);
      if (len[x][y] >= 0) {
        if (len[i][j] > ansl) ansl = len[ansx = i][ansy = j];
        continue;
      }
      cnt = len[x][y] += cnt, getnx(x, y);
      while (x != nx || y != ny) len[x][y] = cnt, getnx(x, y);
      if (len[i][j] > ansl) ansl = len[ansx = i][ansy = j];
    }
  writell(ansx), writell(ansy), writell(ansl, 10);
}
int main() {
  *"" &&
      freopen(
          ""
          ".in",
          "r", stdin) &&
      freopen(
          ""
          ".out",
          "w", stdout),
      gc = fgc, pc = fpc, atexit(fout);
  long long T = readll();
  while (T--) calc();
  return 0;
}
