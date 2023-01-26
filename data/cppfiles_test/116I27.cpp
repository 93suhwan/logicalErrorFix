#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5, mod = 998244353;
long long f[N][2], a[N], t, n, ans;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 0; i <= n; i++) f[i][0] = f[i][1] = 0;
    ans = 0;
    for (long long i = 1; i <= n; i++) {
      long long x = f[a[i]][0] + (a[i] == 0);
      if (a[i] - 1 >= 0) x += f[a[i] - 1][0];
      (f[a[i]][0] += x) %= mod;
      long long y = f[a[i] + 2][0] + f[a[i] + 1][1];
      (f[a[i] + 1][1] += y) %= mod;
      long long z = (a[i] == 1);
      if (a[i] - 2 >= 0) z += f[a[i] - 2][0];
      if (a[i] - 1 >= 0) z += f[a[i] - 1][1], (f[a[i] - 1][1] += z) %= mod;
      (ans += x + y + z) %= mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
