#include <bits/stdc++.h>
using namespace std;
map<long long, long long> vis1[300001], vis2[300001];
long long c[300001], d[300001];
long long t, n, m, k, a[300001], b[300001], ans;
signed main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    ans = 0;
    for (long long i = 1; i <= max(n, m); i++) a[i] = b[i] = 0;
    for (long long i = 1; i <= n; i++) scanf("%lld", &c[i]);
    if (c[n] != 1e6) c[++n] = 1e6;
    for (long long i = 1; i <= m; i++) scanf("%lld", &d[i]);
    if (d[m] != 1e6) d[++m] = 1e6;
    for (long long i = 1; i <= k; i++) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      if (*lower_bound(c, c + n + 1, x) != x) {
        ans += vis1[lower_bound(c, c + n + 1, x) - c][x] *
               (vis1[lower_bound(c, c + n + 1, x) - c][x] - 1) / 2;
        vis1[lower_bound(c, c + n + 1, x) - c][x]++;
        ans -= vis1[lower_bound(c, c + n + 1, x) - c][x] *
               (vis1[lower_bound(c, c + n + 1, x) - c][x] - 1) / 2;
        a[lower_bound(c, c + n + 1, x) - c]++;
      }
      if (*lower_bound(d, d + m + 1, y) != y) {
        ans += vis2[lower_bound(d, d + m + 1, y) - d][y] *
               (vis2[lower_bound(d, d + m + 1, y) - d][y] - 1) / 2;
        vis2[lower_bound(d, d + m + 1, y) - d][y]++;
        ans -= vis2[lower_bound(d, d + m + 1, y) - d][y] *
               (vis2[lower_bound(d, d + m + 1, y) - d][y] - 1) / 2;
        b[lower_bound(d, d + m + 1, y) - d]++;
      }
    }
    for (long long i = 1; i <= n; i++) ans += a[i] * (a[i] - 1) / 2;
    for (long long i = 1; i <= m; i++) ans += b[i] * (b[i] - 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
