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
int T, n, m, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    int k1 = n / m;
    int k2 = (n - m * k1), nex = 1, kk = 1;
    k1 = m - k2;
    for (int i = 1; i <= k; i++) {
      for (int o = 1; o <= m; o++) {
        if (o <= k1) {
          printf("%d ", n / m);
          for (int p = 1; p <= n / m; p++) {
            printf("%d ", nex++);
            if (nex > n) nex -= n;
          }
          printf("\n");
        } else {
          if (o == k1 + 1) kk = nex;
          printf("%d ", n / m + 1);
          for (int p = 1; p <= n / m + 1; p++) {
            printf("%d ", kk++);
            if (kk > n) kk -= n;
          }
          printf("\n");
        }
      }
    }
  }
  return 0;
}
