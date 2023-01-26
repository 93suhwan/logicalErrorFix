#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, q, inc, s1[N], s2[N];
int inv(int x) {
  int res = 1, y = mod - 2;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
signed main() {
  scanf("%d%d", &n, &q);
  inc = rand() % mod;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    (x += inc) %= mod;
    s1[i] = (s1[i - 1] + x) % mod;
    s2[i] = (s2[i - 1] + 1ll * x * x % mod) % mod;
  }
  while (q--) {
    int l, r, d, m;
    scanf("%d%d%d", &l, &r, &d);
    m = r - l + 1;
    int x = (s1[r] - s1[l - 1] - m * (m - 1ll) / 2 % mod * d % mod + mod * 2) *
            inv(m) % mod;
    int y =
        (1ll * m * x % mod * x % mod + m * (m - 1ll) % mod * d % mod * x % mod +
         m * (m - 1ll) * (m * 2 - 1) / 6 % mod * d % mod * d % mod) %
        mod;
    if ((s2[r] - s2[l - 1] + mod) % mod == y)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
