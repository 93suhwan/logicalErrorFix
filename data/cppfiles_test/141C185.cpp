#include <bits/stdc++.h>
using namespace std;
const int MB = 1 << 20;
struct FastIO {
  char ib[MB + 100], *p, *q;
  char ob[MB + 100], *r, stk[128];
  int tp;
  FastIO() { p = q = ib, r = ob, tp = 0; }
  ~FastIO() { fwrite(ob, 1, r - ob, stdout); }
  char read_char() {
    if (p == q) {
      p = ib, q = ib + fread(ib, 1, MB, stdin);
      if (p == q) return 0;
    }
    return *p++;
  }
  template <typename T>
  void read_int(T& x) {
    char c = read_char(), l = 0;
    for (x = 0; !isdigit(c); c = read_char()) l = c;
    for (; isdigit(c); c = read_char()) x = x * 10 - '0' + c;
    if (l == '-') x = -x;
  }
  void write_char(char c) {
    if (r - ob == MB) r = ob, fwrite(ob, 1, MB, stdout);
    *r++ = c;
  }
  template <typename T>
  void write_int(T x) {
    if (x < 0) write_char('-'), x = -x;
    do stk[++tp] = x % 10 + '0';
    while (x /= 10);
    while (tp) write_char(stk[tp--]);
  }
} IO;
const int N = 200010;
int T, n;
long long int a, b, c;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &a, &c);
    b = 0;
    long long int res = 1, fl = 0;
    while (c) {
      int now = a % 10;
      int nowc = c % 10;
      c /= 10;
      a /= 10;
      if (nowc >= now) {
        b += (nowc - now) * res;
      } else {
        nowc = nowc + (c % 10) * 10;
        c /= 10;
        if (nowc - now < 10 && nowc - now >= 0) {
          b += res * (nowc - now);
        } else {
          fl = 1;
          printf("-1\n");
          break;
        }
      }
      res *= 10;
    }
    if ((!fl) && a)
      printf("-1\n");
    else if (!fl)
      printf("%lld\n", b);
  }
  return 0;
}
