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
int a[105];
int main() {
  t = read();
  while (t-- > 0) {
    n = read();
    int res = 1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1 && a[i - 1] == 1)
        res += 5;
      else if (a[i] == 1)
        res++;
      else if (a[i] == 0 && a[i - 1] == 0 && i != 1) {
        res = -1;
        break;
      }
      if (res <= 0) {
        res = -1;
        break;
      }
    }
    write(res), putchar('\n');
  }
  return 0;
}
