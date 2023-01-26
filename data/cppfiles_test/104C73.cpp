#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t, n;
long long m, a[N], b[N], up[N], ans[N];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d %lld", &n, &m);
    long long tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", a + i, b + i);
      b[i] = m - b[i], tot += a[i] + b[i];
      long long l = max(0LL, b[i]), r = min(m, a[i]);
      tot -= 2 * l, ans[i] = l, up[i] = r - l;
    }
    for (int i = 1; i <= n; ++i)
      if (tot > 0) {
        long long out = min(up[i], tot / 2);
        tot -= 2 * out, ans[i] += out;
      }
    printf("%lld\n", abs(tot));
    for (int i = 1; i <= n; ++i) printf("%lld %lld\n", ans[i], m - ans[i]);
  }
  return 0;
}
