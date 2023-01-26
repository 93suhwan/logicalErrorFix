#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fpow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
struct node {
  int x, y, dx, dy;
  bool operator<(const node b) const {
    if (x != b.x) return x < b.x;
    if (y != b.y) return y < b.y;
    if (dx != b.dx) return dx < b.dx;
    if (dy != b.dy) return dy < b.dy;
    return false;
  }
};
map<node, int> vis;
int t[400005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    vis.clear();
    int n, m, a, b, c, d;
    long long p;
    scanf("%d%d%d%d%d%d%lld", &n, &m, &a, &b, &c, &d, &p);
    p = p * fpow(100, mod - 2) % mod;
    int da = 1, db = 1, c1 = 0, c2 = -1;
    while (!vis.count({a, b, da, db})) {
      c2++;
      if (a == c || b == d) {
        t[++c1] = c2;
        vis[{a, b, da, db}] = c1;
      }
      int na = a + da, nb = b + db;
      if (na < 1 || na > n) da = -da;
      if (nb < 1 || nb > m) db = -db;
      a = a + da, b = b + db;
    }
    int last = vis[{a, b, da, db}];
    long long ans = 0, p_ = p;
    for (int i = 1; i < last; i++) {
      ans = (ans + p_ * t[i] % mod);
      p_ = p_ * (1 - p + mod) % mod;
    }
    long long P = fpow(1 - p + mod, c1 - last + 1);
    long long P_ = fpow(1 - P + mod, mod - 2);
    for (int i = last; i <= c1; i++) {
      long long tmp = (t[i] * P_ % mod +
                       (c2 - t[last] + 1) * P % mod * P_ % mod * P_ % mod) %
                      mod;
      ans = (ans + p_ * tmp % mod) % mod;
      p_ = p_ * (1 - p + mod) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
