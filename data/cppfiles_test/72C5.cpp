#include <bits/stdc++.h>
long long w = 1e9, ba, bf, ja, jf, sx, sy, a, b, c, d, p;
long long query(long long x, long long y) {
  printf("? %lld %lld\n", x, y);
  fflush(stdout);
  scanf("%lld", &p);
  return p;
}
int main() {
  ba = query(1, 1), ja = query(w, 1), bf = query(1, w),
  sx = (w + 1 + ba - ja) / 2, sy = (w + 1 + ba - bf) / 2;
  a = 1 + query(sx, 1), b = 1 + query(1, sy), c = w - query(sx, w),
  d = w - query(w, sy);
  printf("! %lld %lld %lld %lld\n", b, a, d, c);
  fflush(stdout);
}
