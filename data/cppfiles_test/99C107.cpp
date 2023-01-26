#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long rd() {
  long long a = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
  return a * f;
}
long long T, x, y;
signed main() {
  T = rd();
  while (T--) {
    x = rd(), y = rd();
    if (x % 2 == 0) {
      long long tmp = y - y % 4;
      y %= 4;
      if (y == 0)
        printf("%lld\n", x);
      else if (y == 1)
        printf("%lld\n", x - tmp - 1);
      else if (y == 2)
        printf("%lld\n", x + 1);
      else
        printf("%lld\n", x + tmp + 4);
    } else {
      long long tmp = y - y % 4;
      y %= 4;
      if (y == 0)
        printf("%lld\n", x);
      else if (y == 1)
        printf("%lld\n", x + tmp + 1);
      else if (y == 2)
        printf("%lld\n", x - 1);
      else
        printf("%lld\n", x - tmp - 4);
    }
  }
  return 0;
}
