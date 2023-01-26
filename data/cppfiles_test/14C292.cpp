#include <bits/stdc++.h>
using namespace std;
long long f[2011][2011], w[2011][2011], a[1001001], T, n, m, k;
signed main() {
  scanf("%lld", &T);
  for (long long ww = 1; ww <= T; ww++) {
    scanf("%lld%lld", &n, &k);
    for (long long i = 0; i <= n + 1; i++)
      for (long long j = 0; j <= n + 1; j++) {
        f[i][j] = 0;
        w[i][j] = 0;
      }
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 0; i <= n; i++) f[n][i] = 0;
    if (n >= a[n]) f[n][n - a[n]] = 1;
    for (long long i = n - 1; i >= 1; i--) {
      for (long long j = 0; j < i; j++) w[i][j] = w[i + 1][j];
      if (i >= a[i]) w[i][i - a[i]]++;
    }
    long long ans = n + 1;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j <= i; j++) {
        bool add = 0;
        if (i - a[i] - j == 0) add = 1;
        f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + add);
        if (f[i][j] + w[i + 1][j] >= k) ans = min(ans, j);
      }
    }
    if (ans > n)
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
