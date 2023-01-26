#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2000005;
struct Node {
  long long x, y;
} b[MAXN];
long long a[MAXN], n, sum, m;
void Solve() {
  scanf("%lld", &n);
  sum = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  sort(a + 1, a + 1 + n);
  a[0] = 0;
  scanf("%lld", &m);
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long long p = lower_bound(a + 1, a + 1 + n, x) - a;
    long long ans = (long long)1e18;
    long long c1;
    long long c2;
    if (p >= n + 1)
      c1 = (x - a[n]) + max(0ll, y - (sum - a[n]));
    else
      c1 = max(0ll, y - (sum - a[p]));
    if (p == 1)
      c2 = (long long)1e18;
    else
      c2 = max(0ll, y - (sum - a[p - 1])) + (x - a[p - 1]);
    ans = min(c1, c2);
    printf("%lld\n", ans);
  }
}
signed main() {
  signed TT;
  TT = 1;
  while (TT--) {
    Solve();
  }
  return 0;
}
