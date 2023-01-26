#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, m = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') m = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * m;
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
signed main() {
  long long t = read();
  while (t--) {
    long long n = read(), m = read();
    long long k = read();
    long long minx1 = 0x3f3f3f3f, maxx1 = -0x3f3f3f3f;
    long long minx2 = 0x3f3f3f3f, maxx2 = -0x3f3f3f3f;
    long long miny1 = 0x3f3f3f3f, maxy1 = -0x3f3f3f3f;
    long long miny2 = 0x3f3f3f3f, maxy2 = -0x3f3f3f3f;
    for (long long i = 1; i <= k; i++) {
      long long x = read();
      minx1 = min(minx1, x);
      maxx1 = max(maxx1, x);
    }
    k = read();
    for (long long i = 1; i <= k; i++) {
      long long x = read();
      minx2 = min(minx2, x);
      maxx2 = max(maxx2, x);
    }
    k = read();
    for (long long i = 1; i <= k; i++) {
      long long y = read();
      miny1 = min(miny1, y);
      maxy1 = max(maxy1, y);
    }
    k = read();
    for (long long i = 1; i <= k; i++) {
      long long y = read();
      miny2 = min(miny2, y);
      maxy2 = max(maxy2, y);
    }
    write(max(m * max(maxx2 - minx2, maxx1 - minx1),
              n * max(maxy1 - miny1, maxy2 - miny2)));
    putchar('\n');
  }
}
