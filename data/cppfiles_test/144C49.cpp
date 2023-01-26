#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0;
  bool f = 0;
  char ch = ' ';
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f) ? (-s) : (s);
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar((x % 10) + '0');
}
const int N = 200005;
int T, n, m, k, wwx[N];
int main() {
  int i, j, L, L1, pp, qq, wn, wq;
  T = read();
  while (T--) {
    n = read();
    m = read();
    k = read();
    if (n % m == 0) {
      pp = n / m;
      L = n;
      while (k--) {
        for (i = 1; i <= m; i++) {
          write(pp), putchar(' ');
          for (j = 1; j <= pp; j++) {
            write(L % n + 1), putchar(' ');
            L++;
          }
          putchar('\n');
        }
      }
      continue;
    } else {
      pp = n / m + 1;
      qq = n / m;
      wn = n % m;
      wq = m - wn;
      L = n;
      while (k--) {
        for (i = 1; i <= wn; i++) {
          write(pp), putchar(' ');
          for (j = 1; j <= pp; j++) {
            write(L % n + 1), putchar(' ');
            L++;
          }
          putchar('\n');
        }
        L1 = L;
        for (i = 1; i <= wq; i++) {
          write(qq), putchar(' ');
          for (j = 1; j <= qq; j++) {
            write(L1 % n + 1), putchar(' ');
            L1++;
          }
          putchar('\n');
        }
      }
    }
    putchar('\n');
  }
  return 0;
}
