#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool bz[100005][2][2];
int n, m, rb, cb, rd, cd, p, T;
int ksm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
int id(int x, int y) { return (x - 1) * m + y; }
int tr(int x) { return x == -1 ? 0 : 1; }
void work() {
  scanf("%d%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd, &p);
  p = 1ll * p * ksm(100, mod - 2) % mod;
  p = (1ll - 1ll * p + 1ll * mod) % mod;
  memset(bz, 0, sizeof(bz));
  int p1 = 1, p2 = 1, ans = 0, ans2 = 0, dc = 1, dr = 1;
  while (!bz[id(rb, cb)][tr(dr)][tr(dc)]) {
    bz[id(rb, cb)][tr(dr)][tr(dc)] = 1;
    if (rb == rd || cb == cd) p1 = 1ll * p1 * p % mod;
    if (!(1 <= rb + dr && rb + dr <= n)) dr = -dr;
    if (!(1 <= cb + dc && cb + dc <= m)) dc = -dc;
    rb += dr;
    cb += dc;
    ans = (1ll * ans + 1ll * p1) % mod;
  }
  printf("%d %d\n", dr, dc);
  p2 = 1;
  memset(bz, 0, sizeof(bz));
  while (!bz[id(rb, cb)][tr(dr)][tr(dc)]) {
    bz[id(rb, cb)][tr(dr)][tr(dc)] = 1;
    if (rb == rd || cb == cd) p2 = 1ll * p2 * p % mod;
    if (!(1 <= rb + dr && rb + dr <= n)) dr = -dr;
    if (!(1 <= cb + dc && cb + dc <= m)) dc = -dc;
    rb += dr;
    cb += dc;
    ans2 = (1ll * ans2 + 1ll * p2) % mod;
  }
  printf("%d %d\n", dr, dc);
  printf("%d %d\n", ans, ans2);
  ans2 =
      1ll * ans2 * ksm((1ll - 1ll * p2 + 1ll * mod), mod - 2) % mod * p1 % mod;
  ans = (1ll * ans + 1ll * ans2) % mod;
  printf("%d\n\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
