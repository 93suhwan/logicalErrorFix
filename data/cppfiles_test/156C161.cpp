#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long N = 2e5 + 5;
long long a[N];
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n, k, minn = INF;
    scanf("%lld%lld", &n, &k);
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      k -= a[i];
      minn = min(minn, a[i]);
    }
    for (long long i = 1; i <= n; i++) a[i] -= minn;
    k = -k;
    if (k <= 0)
      puts("0");
    else {
      sort(a + 1, a + 1 + n, greater<long long>());
      long long ans = k;
      for (long long i = 1; i < n; i++) {
        k -= a[i];
        k = max(0ll, k);
        ans = min(ans, k / (i + 1) + (k % (i + 1) != 0) + i);
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
