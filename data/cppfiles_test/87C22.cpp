#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 1e5 + _;
const int fbin = (1 << 17) + _;
const int mod = 998244353;
inline int ad(int x, int y) { return x >= mod - y ? x - mod + y : x + y; }
inline int re(int x, int y) { return x < y ? x - y + mod : x - y; }
inline int mu(int x, int y) { return (long long)x * y % mod; }
inline int qp(int x, long long y) {
  int r = 1;
  while (y) {
    if (y & 1) r = mu(r, x);
    x = mu(x, x);
    y >>= 1;
  }
  return r;
}
inline int iv(int x) { return qp(x, mod - 2); }
inline int dv(int x, int y) { return mu(x, qp(y, mod - 2)); }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long d) {
  if (d < 0) {
    putchar('-');
    d = -d;
  }
  if (d >= 10) write(d / 10);
  putchar(d % 10 + '0');
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x, now = 1, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (x > now) s += x - now, now = x;
      now++;
    }
    printf("%d\n", s);
  }
  return 0;
}
