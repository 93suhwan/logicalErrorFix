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
    long long n = read(), m = read(), k = read();
    if (k == 0) {
      if (n % 2 == 0)
        puts("YES");
      else
        puts("NO");
    } else {
      if (n % 2 == 0) {
        if (k > n * (m / 2))
          puts("NO");
        else if (k % 2 == 0)
          puts("YES");
        else
          puts("NO");
      } else {
        if (k < m / 2)
          puts("NO");
        else if ((k - m / 2) % 2 == 0)
          puts("YES");
        else
          puts("NO");
      }
    }
  }
}
