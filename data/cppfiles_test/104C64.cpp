#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5, inf = 0x3f3f3f3f, mod = 998244353;
const double eps = 1e-6;
long long n, a[maxn], b[maxn], T, m;
long long ans1[maxn], ans2[maxn], d[maxn], l[maxn], r[maxn];
int main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld", &n, &m);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld%lld", &a[i], &b[i]);
      ans1[i] = min(a[i], m);
      ans2[i] = m - ans1[i];
      l[i] = (a[i] - ans1[i]) - (b[i] - ans2[i]);
      ans2[i] = min(b[i], m);
      ans1[i] = m - ans2[i];
      r[i] = (a[i] - ans1[i]) - (b[i] - ans2[i]);
      sum += r[i];
    }
    if (sum > 0) {
      for (int i = 1; i <= n; i++) {
        d[i] = r[i] - l[i];
        if (sum > d[i]) {
          sum -= d[i];
          ans1[i] += d[i] / 2;
          ans2[i] -= d[i] / 2;
        } else {
          int now = (sum + 1) / 2 * 2;
          sum -= now;
          ans1[i] += now / 2;
          ans2[i] -= now / 2;
        }
      }
    }
    printf("%lld\n", abs(sum));
    for (int i = 1; i <= n; i++) {
      printf("%lld %lld\n", ans1[i], ans2[i]);
    }
  }
}
