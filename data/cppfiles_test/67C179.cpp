#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
  return x * w;
}
void work() {
  int a = read(), b = read(), c = read();
  if (a > b) swap(a, b);
  int d, n = (b - a) * 2;
  if (a > n / 2 || b <= n / 2 || c > n || c <= 0) {
    printf("-1\n");
    return;
  }
  if (c > n / 2) {
    d = c - n / 2;
  } else
    d = n / 2 + c;
  if (d <= 0 || d > n)
    printf("-1\n");
  else
    printf("%d\n", d);
}
int main() {
  int T = read();
  while (T--) work();
}
