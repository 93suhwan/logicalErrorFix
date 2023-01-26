#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
namespace GTI {
char gc(void) {
  const int S = 1 << 16;
  static char buf[S], *s = buf, *t = buf;
  if (s == t) t = buf + fread(s = buf, 1, S, stdin);
  if (s == t) return EOF;
  return *s++;
}
ll gti(void) {
  ll a = 0, b = 1, c = gc();
  for (; !isdigit(c); c = gc()) b ^= (c == '-');
  for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
  return b ? a : -a;
}
int gts(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
int gtl(char *s) {
  int len = 0, c = gc();
  for (; isspace(c); c = gc())
    ;
  for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
  s[len] = 0;
  return len;
}
}  // namespace GTI
using GTI::gti;
using GTI::gtl;
using GTI::gts;
const int M = 1e9 + 7;
int fpw(int a, int b) {
  a %= M, b %= M - 1;
  if (b < 0) b += M - 1;
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % M)
    if (b & 1) c = 1ll * c * a % M;
  return c;
}
int calcpk(int p) { return fpw(1 - p, -1); }
int calckpk(int p) { return 1ll * p * fpw(1 - p, -2) % M; }
int main(void) {
  for (int T = gti(); T; T--) {
    int n = gti(), m = gti(), rb = gti(), cb = gti(), rd = gti(), cd = gti(),
        p = (1 - 1ll * gti() * fpw(100, -1)) % M;
    std::vector<int> d;
    int x = rb, y = cb, dx = 1, dy = 1, tall = 0;
    if (x + dx < 1 || x + dx > n) dx = -dx;
    if (y + dy < 1 || y + dy > m) dy = -dy;
    int pdx = dx, pdy = dy;
    for (int i = 0; true; i++) {
      if (x == rd || y == cd) d.push_back(i);
      x += dx, y += dy;
      if (x + dx < 1 || x + dx > n) dx = -dx;
      if (y + dy < 1 || y + dy > m) dy = -dy;
      if (x == rb && y == cb && dx == pdx && dy == pdy) {
        tall = i + 1;
        break;
      }
    }
    int pall = fpw(p, d.size()), last = 1, ans = 0;
    for (auto t : d) {
      ans = (ans + 1ll * t * last % M * (1 - p) % M * calcpk(pall)) % M;
      ans = (ans + 1ll * tall * last % M * (1 - p) % M * calckpk(pall)) % M;
      last = 1ll * last * p % M;
    }
    printf("%d\n", (ans % M + M) % M);
  }
  return 0;
}
