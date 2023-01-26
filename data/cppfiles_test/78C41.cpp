#include <bits/stdc++.h>
char ibuf[1 << 15], *p1, *p2;
struct {
  inline int rint() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register int unsigned a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline long long rll() {
    register char c, f = 0;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) < 48 ||
           c > 57)
      f |= c == '-';
    register uint64_t a = c & 15;
    while ((c = (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 15, stdin),
                              p1 == p2)
                     ? EOF
                     : *p1++)) >= 48 &&
           c <= 57)
      a = a * 10 + (c & 15);
    return f ? ~a + 1 : a;
  }
  inline operator int() { return rint(); }
  inline operator long long() { return rll(); }
} g90;
const int LN = 32, N = 233333;
int a[N], cnt[LN];
inline int gcd(const int& a, const int& b) { return b ? gcd(b, a % b) : a; }
signed main() {
  for (int T = g90; T--;) {
    int n = g90, l = 30;
    for (int i = 0; i <= l; i++) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = g90;
      for (int k = 0; k <= l; ++k) {
        if (a[i] >> k & 1) cnt[k]++;
      }
    }
    int g = 0;
    for (int k = 0; k <= l; ++k) {
      g = gcd(cnt[k], g);
    }
    for (int i = 1; i <= n; i++)
      if (!(g % i)) printf("%d ", i);
    puts("");
  }
}
