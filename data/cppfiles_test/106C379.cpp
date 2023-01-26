#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f = ch == '-' ? -1 : f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(int x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
int n, t;
int main() {
  t = read();
  while (t-- > 0) {
    n = read();
    for (int i = 1; i <= n; ++i) write(i + 1), putchar(' ');
    puts("");
  }
  return 0;
}
