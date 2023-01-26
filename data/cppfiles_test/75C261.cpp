#include <bits/stdc++.h>
using namespace std;
inline void read() {}
template <typename T, typename... Ts>
inline void read(T& A, Ts&... As) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  A = x * f, read(As...);
}
inline void write(char a) { putchar(a); }
template <typename T>
inline void write(T a) {
  if (a < 0ll) putchar('-'), a = -a;
  if (a > 9ll) write(a / 10ll);
  putchar(a % 10ll + '0');
}
template <typename T, typename... Ts>
inline void write(T A, Ts... As) {
  write(A), write(As...);
}
const int N = 100010;
int t, n, a[N], ans, b[N], x, p[N];
signed main() {
  read(t);
  while (t--) {
    read(n), ans = 0;
    for (register int i = 1; i <= n; ++i) {
      read(a[i]), p[i] = i;
      b[i] = 0;
      for (register int j = 0; j < a[i]; ++j) {
        read(x), b[i] = max(x - j, b[i]);
      }
    }
    sort(p + 1, p + n + 1, [&](int x, int y) { return b[x] < b[y]; });
    x = 0;
    for (register int i = 1; i <= n; ++i) {
      ans = max(ans, b[p[i]] - x);
      x += a[p[i]];
    }
    write(ans + 1, '\n');
  }
  return 0;
}
