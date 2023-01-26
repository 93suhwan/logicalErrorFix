#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c = 1LL * c * a % mod;
    b >>= 1;
    a = 1LL * a * a % mod;
  }
  return c;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, x1, y1, x2, y2, p;
    scanf("%d%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2, &p);
    --x1, --x2, --y1, --y2;
    int oldx1 = x1, oldy1 = y1;
    p = 1LL * p * power(100, mod - 2) % mod;
    int q = (mod + 1 - p) % mod;
    int dx = 1, dy = 1;
    if (x1 + dx < 0 || x1 + dx >= n) dx = -dx;
    if (y1 + dy < 0 || y1 + dy >= m) dy = -dy;
    int cnt = 0, cur = 0, coef = 1;
    int olddx = dx, olddy = dy;
    while (1) {
      if (x1 == x2 || y1 == y2) {
        coef = 1LL * coef * q % mod;
      }
      cur = (cur + coef) % mod;
      ++cnt;
      x1 += dx, y1 += dy;
      if (x1 + dx < 0 || x1 + dx >= n) dx = -dx;
      if (y1 + dy < 0 || y1 + dy >= m) dy = -dy;
      if (x1 == oldx1 && y1 == oldy1 && olddx == dx && olddy == dy) break;
    }
    assert(coef != 1);
    printf("%d\n",
           int(1LL * cur * power((mod + 1 - coef) % mod, mod - 2) % mod));
  }
  return 0;
}
