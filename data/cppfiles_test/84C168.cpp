#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == -1 ? ~x + 1 : x;
}
int main() {
  int T = read();
  while (T--) {
    int n = read(), s = read();
    n -= ((n + 1 >> 1) - 1);
    printf("%d\n", s / n);
  }
}
