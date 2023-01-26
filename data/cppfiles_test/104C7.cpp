#include <bits/stdc++.h>
using namespace std;
long long a[1001001], b[1001001], eat[1001001], T, n, m, tot, minv, maxv;
signed main() {
  scanf("%lld", &T);
  for (long long ww = 1; ww <= T; ww++) {
    tot = 0;
    minv = 0;
    maxv = 0;
    scanf("%lld%lld", &n, &m);
    for (long long i = 1; i <= n; i++) {
      scanf("%lld%lld", &a[i], &b[i]);
      minv += max(a[i] - m, 0ll);
      maxv += min(a[i], a[i] - m + b[i]);
      tot += a[i] + b[i] - m;
    }
    if (tot <= 2 * minv) {
      printf("%lld\n", 2 * minv - tot);
      for (long long i = 1; i <= n; i++) {
        long long lft = max(a[i] - m, 0ll);
        printf("%lld %lld\n", a[i] - lft, m - a[i] + lft);
      }
    } else if (tot >= 2 * maxv) {
      printf("%lld\n", tot - 2 * maxv);
      for (long long i = 1; i <= n; i++) {
        long long lft = min(a[i], a[i] - m + b[i]);
        printf("%lld %lld\n", a[i] - lft, m - a[i] + lft);
      }
    } else {
      printf("%lld\n", tot & 1);
      tot -= 2 * minv - (tot & 1);
      for (long long i = 1; i <= n; i++) eat[i] = max(a[i] - m, 0ll);
      for (long long i = 1; i <= n; i++) {
        long long now = min(a[i], a[i] - m + b[i]);
        if (tot >= 2 * (now - eat[i])) {
          tot -= 2 * (now - eat[i]);
          eat[i] = now;
        } else {
          eat[i] += tot / 2;
          tot = 0;
          break;
        }
      }
      for (long long i = 1; i <= n; i++)
        printf("%lld %lld\n", a[i] - eat[i], m - a[i] + eat[i]);
    }
  }
  return 0;
}
