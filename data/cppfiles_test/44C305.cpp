#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long su = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) su = su * 10 + c - '0';
  return su * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
int T, x, y, n, m;
signed main() {
  T = read();
  while (T--) {
    x = 0, y = 0, n = read(), m = read();
    if ((x + y) % 2 != (n + m) % 2)
      puts("-1");
    else {
      if (x == n && y == m)
        puts("0");
      else if (n - x == m - y || x + y == n + m)
        puts("1");
      else
        puts("2");
    }
  }
}
