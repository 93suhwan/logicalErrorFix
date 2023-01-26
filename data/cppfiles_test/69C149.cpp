#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long s[100], t[100];
long long dis(long long x, long long y) {
  long long res = 0, cs = 0, ct = 0;
  while (x) {
    s[++cs] = x % 10;
    x /= 10;
  }
  while (y) {
    t[++ct] = y % 10;
    y /= 10;
  }
  while (cs && ct) {
    if (s[cs] == t[ct])
      --ct;
    else
      ++res;
    --cs;
  }
  return res + ct + cs;
}
signed main() {
  long long T, n, ans;
  T = read();
  while (T--) {
    n = read();
    ans = 100;
    for (long long i = 1, j = 1; j <= 62; i = i * 2, ++j)
      ans = min(ans, dis(n, i));
    printf("%lld\n", ans);
  }
  return 0;
}
