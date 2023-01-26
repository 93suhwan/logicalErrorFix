#include <bits/stdc++.h>
inline int read() {
  int num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline int re1d() {
  char c = getchar();
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline int min(int a, int b) { return a > b ? b : a; }
inline int max(int a, int b) { return a < b ? b : a; }
long long a111, a110, a000, a001, a010, a011, a100, a101;
signed main() {
  int n = read();
  long long a00 = 0, a01 = 0, a10 = 0, a11 = 0;
  for (int i = 1; i <= (n); i++) {
    int xx = read(), yy = read();
    int x = xx & 2, y = yy & 2;
    int q = (xx & 4) ^ (yy ^ 4);
    if (x && y) {
      a11++;
      if (q)
        a111++;
      else
        a110++;
    } else if (x) {
      a10++;
      if (q)
        a101++;
      else
        a100++;
    } else if (y) {
      a01++;
      if (q)
        a011++;
      else
        a010++;
    } else {
      a00++;
      if (q)
        a001++;
      else
        a000++;
    }
  }
  long long ans = 0;
  ans += a00 * (a00 - 1) / 2 * (a11 + a01 + a10);
  ans += a01 * (a01 - 1) / 2 * (a11 + a00 + a10);
  ans += a10 * (a10 - 1) / 2 * (a11 + a01 + a00);
  ans += a11 * (a11 - 1) / 2 * (a00 + a01 + a10);
  ans += a00 * (a00 - 1) / 2 * (a00 - 2) / 3;
  ans += a01 * (a01 - 1) / 2 * (a01 - 2) / 3;
  ans += a10 * (a10 - 1) / 2 * (a10 - 2) / 3;
  ans += a11 * (a11 - 1) / 2 * (a11 - 2) / 3;
  printf("%lld\n", ans);
  return 0;
}
