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
      long long x = f[a[i]][0] + (a[i] == 1), y = f[a[i]][1] + (a[i] == 0);
      if (a[i] >= 2) (x += f[a[i] - 2][1]) %= mod;
      if (a[i] >= 1) (y += f[a[i] - 1][1]) %= mod;
      ans = ((x + y) % mod + ans) % mod;
      (f[a[i]][0] += x) %= mod, (f[a[i]][1] += y) %= mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
