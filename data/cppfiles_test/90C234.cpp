#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
long long cas, x, y;
signed main() {
  cas = read();
  while (cas--) {
    x = read(), y = read();
    if (x > y) {
      printf("%lld\n", x + y);
    } else {
      if (x == y)
        printf("%lld\n", x);
      else {
        long long mid = (x + y) / 2;
        long long p = ((y - x) / 2 - mid % x) / x;
        printf("%lld\n", mid + p * x);
      }
    }
  }
  return 0;
}
