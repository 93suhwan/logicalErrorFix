#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int res = 0, flag = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = res * 10 + ch - '0';
    ch = getchar();
  }
  return res * flag;
}
int T, a, b, n;
int main() {
  T = read();
  while (T--) {
    a = read();
    b = read();
    n = a + b;
    if (a > b) swap(a, b);
    int l = (n - 2 * a) / 2, r = (n - 2 * a + 1) / 2 + 2 * a;
    if (n & 1) {
      printf("%d\n", r - l + 1);
      for (register int i = l; i <= r; ++i) printf("%d ", i);
    } else {
      printf("%d\n", (r - l) / 2 + 1);
      for (register int i = l; i <= r; i += 2) printf("%d ", i);
    }
    puts("");
  }
  return 0;
}
