#include <bits/stdc++.h>
using namespace std;
int t, n, k, c, r, z;
bool ok(int n) {
  z = 0;
  while (n) {
    z |= (1 << (n % 10));
    n /= 10;
  }
  return __builtin_popcount(z) <= k;
}
void solve() {
  while (!ok(n)) {
    r = 1;
    c = n;
    while (!ok(c)) {
      c /= 10;
      r *= 10;
    }
    r /= 10;
    n = (n / r + 1) * r;
  }
}
signed main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    solve();
    printf("%d\n", n);
  }
}
