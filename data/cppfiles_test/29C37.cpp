#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5;
long long n, a[300005], ans, s;
long long c1[300005], c2[300005];
void fix1(long long x, long long v) {
  for (long long i = x; i <= N; i += (i & -i)) c1[i] += v;
}
long long ask1(long long x) {
  long long s = 0;
  for (long long i = x; i >= 1; i -= (i & -i)) s += c1[i];
  return s;
}
void fix2(long long x, long long v) {
  for (long long i = x; i <= N; i += (i & -i)) c2[i] += v;
}
long long ask2(long long x) {
  long long s = 0;
  for (long long i = x; i >= 1; i -= (i & -i)) s += c2[i];
  return s;
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; cin >> a[i++])
    ;
  for (long long i = 1; i <= n; i++) {
    s += a[i];
    fix1(a[i], 1);
    ans = ans + s + (i - 1) * a[i] - ask2(a[i]);
    for (long long j = 1; j <= N / a[i]; j++) {
      ans -= a[i] * j * (ask1(min(N, a[i] * (j + 1) - 1)) - ask1(a[i] * j - 1));
      fix2(a[i] * j, a[i] * j), fix2(a[i] * (j + 1), -a[i] * j);
    }
    printf("%lld ", ans);
  }
  return puts(""), 0;
}
