#include <bits/stdc++.h>
using namespace std;
long long T, n, k;
long long a[100], s[100], pre[18];
signed main() {
  scanf("%lld", &T);
  pre[0] = 1;
  for (long long i = 1; i <= 18; i++) pre[i] = pre[i - 1] * 10;
  while (T--) {
    scanf("%lld%lld", &n, &k);
    k++;
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), s[i] = 0;
    for (long long i = 1; i <= n - 1; i++) {
      long long t = pre[a[i + 1] - a[i]] - 1;
      if (t < k) {
        s[i] = t;
        k -= t;
      } else {
        s[i] = k;
        k = 0;
        break;
      }
    }
    if (k) s[n] = k;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) ans += s[i] * pre[a[i]];
    printf("%lld\n", ans);
  }
}
