#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long n = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n * f;
}
long long vis[400005][2][2];
long long tans[1000005], cnt;
long long ksm(long long n, long long k) {
  long long ans = 1;
  while (k >= 1) {
    if (k & 1) ans = 1LL * ans * n % 1000000007;
    k >>= 1;
    n = 1LL * n * n % 1000000007;
  }
  return ans;
}
signed main() {
  long long t, n, m, x1, y1, x2, y2, tx, ty, ans, bs = 0, gre = 0, p, cm;
  t = read();
  for (long long greg = 1; greg <= t; greg++) {
    n = read();
    m = read();
    x1 = read();
    y1 = read();
    x2 = read();
    y2 = read();
    p = read();
    p = 1LL * p * ksm(100, 1000000007 - 2) % 1000000007;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        vis[(i - 1) * m + j][0][0] = -1;
        vis[(i - 1) * m + j][0][1] = -1;
        vis[(i - 1) * m + j][1][0] = -1;
        vis[(i - 1) * m + j][1][1] = -1;
      }
    }
    tx = 1;
    ty = 1;
    if (x1 + tx > n || x1 + tx <= 0) tx = -tx;
    if (y1 + ty > m || y1 + ty <= 0) ty = -ty;
    vis[(x1 - 1) * m + y1][(tx + 1) / 2][(ty + 1) / 2] = 0;
    ans = 0;
    cnt = 0;
    if (x1 == x2 || y1 == y2) tans[++cnt] = 0;
    while (1) {
      x1 += tx;
      y1 += ty;
      if (x1 + tx > n || x1 + tx <= 0) tx = -tx;
      if (y1 + ty > m || y1 + ty <= 0) ty = -ty;
      ans++;
      if (vis[(x1 - 1) * m + y1][(tx + 1) / 2][(ty + 1) / 2] != -1) {
        bs = ans - vis[(x1 - 1) * m + y1][(tx + 1) / 2][(ty + 1) / 2];
        break;
      }
      vis[(x1 - 1) * m + y1][(tx + 1) / 2][(ty + 1) / 2] = ans;
      if (x1 == x2 || y1 == y2) tans[++cnt] = ans;
    }
    gre = 0;
    cm = ksm(1000000007 + 1 - p, cnt);
    cm = ksm(1000000007 + 1 - cm, 1000000007 - 2);
    for (long long i = 1; i <= cnt; i++) {
      if (tans[i] == 0) {
        gre = (gre + 1LL * bs * ksm(1000000007 + 1 - p, i - 1) % 1000000007 *
                         p % 1000000007 * cm % 1000000007 * cm % 1000000007 *
                         ksm(1000000007 + 1 - p, cnt) % 1000000007) %
              1000000007;
        continue;
      }
      long long cj = 1LL * ksm(1000000007 + 1 - p, i - 1) * p % 1000000007 *
                     tans[i] % 1000000007;
      long long sth = 1LL * bs * ksm(tans[i], 1000000007 - 2) % 1000000007;
      gre = (gre + 1LL * cj * cm % 1000000007 +
             1LL * cj * sth % 1000000007 * cm % 1000000007 * cm % 1000000007 *
                 ksm(1000000007 + 1 - p, cnt)) %
            1000000007;
    }
    printf("%lld\n", gre);
  }
  return 0;
}
