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
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
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
int qry(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  assert(x >= 1 && x <= 1e9 && y >= 1 && y <= 1e9);
  return read();
}
int main() {
  int a = qry(1, 1), b = qry(1e9, 1), c = qry(1, 1e9);
  int lb = 1, rb = 1e9, ub = 1, db = 1e9;
  if (a < b)
    rb -= b - a;
  else
    lb += a - b;
  if (a < c)
    db -= c - a;
  else
    ub += a - c;
  assert(lb < rb && ub < db);
  int d1 = qry((lb + rb) / 2, 1);
  int d2 = qry(1, (ub + db) / 2);
  printf("! %d %d %d %d", lb + d2, ub + d1, rb - d2, db - d1);
  assert(lb + d2 <= rb - d2 && ub + d1 <= db - d1);
  fflush(stdout);
  return 0;
}
