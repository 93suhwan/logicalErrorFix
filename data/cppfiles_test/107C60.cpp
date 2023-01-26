#include <bits/stdc++.h>
char ibuf[1 << 15], *p1, *p2;
struct FastIO {
  inline int rint() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register int unsigned a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline long long rll() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register unsigned long long a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline operator int() { return rint(); }
} g90;
const int N = 100100;
signed main() {
  int T = 1;
  T = g90;
  for (; T--;) {
    static int p[N];
    int n = g90, a = g90, b = g90;
    if (a < b - 1 || a > b + 1 || a + b > n - 2) {
      puts("-1");
      continue;
    } else if (a == b + 1) {
      for (int i = 1; i <= n - 1 - a - b; ++i) {
        p[i] = i;
      }
      for (int i = n - a - b, j = n; i <= n; i += 2, j--) {
        p[i] = j;
      }
      for (int i = n - a - b + 1, j = n - a - b; i <= n; i += 2, j++) {
        p[i] = j;
      }
    } else {
      for (int i = 1; i <= n - 1 - a - b; ++i) {
        p[i] = n - i + 1;
      }
      for (int i = n - a - b, j = 1; i <= n; i += 2, j++) {
        p[i] = j;
      }
      for (int i = n - a - b + 1, j = n - (n - a - b) + 1; i <= n;
           i += 2, j--) {
        p[i] = j;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", p[i]);
    }
    puts("");
  }
}
