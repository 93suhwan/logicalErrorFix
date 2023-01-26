#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 7;
long long a[maxn];
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n, k, sum = 0;
    scanf("%lld%lld", &n, &k);
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    if (sum <= k) {
      puts("       0");
      continue;
    }
    sort(a + 1, a + 1 + n);
    long long d = sum - k;
    long long ans = d;
    for (long long i = n; i >= 2; i--) {
      long long len = n - i + 1;
      d = d - a[i] + a[1];
      long long step = d / (len + 1);
      if (d > 0 && d % (len + 1)) step++;
      ans = min(ans, step + len);
    }
    printf("         %lld\n", ans);
  }
}
