#include <bits/stdc++.h>
using namespace std;
long long T, n, m, f[201][201], e[201][201], a[1001001], ans;
signed main() {
  scanf("%lld", &T);
  for (long long ww = 1; ww <= T; ww++) {
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 1; i <= n; i++) f[i][0] = f[i - 1][0] + (a[i] == i);
    for (long long i = n; i > 0; i--) e[i][0] = e[i + 1][0] + (a[i] == i);
    ans = 1ll << 50;
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= i; j++)
        f[i][j] = max(f[i - 1][j] + (a[i] == i - j), f[i - 1][j - 1]);
    for (long long i = n; i > 0; i--)
      for (long long j = 1; j <= n - i; j++)
        e[i][j] = max(e[i + 1][j + 1], e[i + 1][j] + (a[i] == i - j));
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= n; j++)
        if (f[i][j] + e[i + 1][j] >= m) ans = min(ans, j);
    if (ans != 1ll << 50)
      printf("%lld\n", ans);
    else
      puts("-1");
    for (long long i = 0; i <= n; i++)
      for (long long j = 0; j <= n; j++) {
        f[i][j] = 0;
        e[i][j] = 0;
      }
  }
  return 0;
}
