#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x * f;
}
const long long N = 5e5 + 5, mod = 998244353;
long long a[N], dp[N][2], t[N][2], mi[N], n, ans, res;
signed main(void) {
  mi[0] = 1;
  for (long long i = 1; i <= 500000; i++) mi[i] = mi[i - 1] * 2, mi[i] %= mod;
  long long T = read();
  while (T--) {
    n = read(), ans = res = 0;
    for (long long i = 1; i <= n; i++) a[i] = read();
    for (long long i = 1; i <= n; i++) {
      dp[i][0] += t[a[i] - 1][0] + t[a[i]][0], dp[i][0] %= mod;
      if (a[i] >= 2) dp[i][1] += t[a[i] - 2][0] + t[a[i]][1], dp[i][1] %= mod;
      if (a[i] == 1) ans += mi[res], res++, ans %= mod;
      if (a[i] == 0) dp[i][0] += 1;
      t[a[i]][0] += dp[i][0], t[a[i]][1] += dp[i][1], t[a[i]][0] %= mod,
          t[a[i]][1] %= mod;
    }
    for (long long i = 1; i <= n; i++) {
      ans += dp[i][0] + dp[i][1], ans %= mod;
      t[a[i]][0] = t[a[i]][1] = 0, dp[i][0] = dp[i][1] = 0;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
