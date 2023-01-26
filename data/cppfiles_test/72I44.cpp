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
  return read();
}
int main() {
  int a = qry(1, 1), b = qry(1e9, 1), c = qry(1, 1e9);
  int d = qry(1e9, 1e9);
  assert((a - b == c - d) && (a - c == b - d));
  int lb = 1, rb = 1e9, ub = 1, db = 1e9;
  if (a < b)
    rb -= b - a;
  else
    lb += a - b;
  if (a < c)
    db -= c - a;
  else
    ub += a - c;
  int t1 = (lb + rb) / 2, t2 = (ub + db) / 2;
  int ax = qry(t2, 1) + 1, ay = qry(1, t1) + 1, bx = 1e9 - qry(t2, 1e9),
      by = 1e9 - qry(1e9, t1);
  printf("! %d %d %d %d\n", ax, ay, bx, by);
  fflush(stdout);
  return 0;
}
