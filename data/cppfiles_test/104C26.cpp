#include <bits/stdc++.h>
using namespace std;
long long n, m, T, ans, eat_a, min_a, max_a, max_b, lower, upper, a[200005],
    b[200005], l[200005], r[200005];
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 1) + (s << 3) + ch - '0';
    ch = getchar();
  }
  return s * f;
}
signed main() {
  for (long long t = read(); t; --t) {
    n = read(), m = read(), T = max_a = max_b = lower = upper = 0;
    for (long long i = 1; i <= n; ++i)
      a[i] = read(), b[i] = read(), T += a[i] - b[i], max_a += min(m, a[i]),
      max_b += min(m, b[i]),
      lower += max(a[i] - m, 0ll) + max(m - a[i], 0ll) - b[i],
      upper += a[i] - max(m - b[i], 0ll) - max(b[i] - m, 0ll);
    if (lower >= 1) {
      printf("%lld\n", lower);
      for (long long i = 1; i <= n; ++i)
        printf("%lld %lld\n", a[i] - max(a[i] - m, 0ll), max(m - a[i], 0ll));
    } else if (upper <= -1) {
      printf("%lld\n", -upper);
      for (long long i = 1; i <= n; ++i)
        printf("%lld %lld\n", max(m - b[i], 0ll), b[i] - max(b[i] - m, 0ll));
    } else {
      min_a = n * m - max_b;
      printf("%lld\n", upper % 2);
      if (T < 0) {
        eat_a = min_a;
        if (T + 2 * max_b - n * m >= 0) eat_a = min(max_a, (T + n * m + 1) / 2);
      } else {
        eat_a = max_a;
        if (T - 2 * max_a + n * m <= 0) eat_a = min(max_a, (T + n * m + 1) / 2);
      }
      ans = eat_a - min_a;
      for (long long i = 1, add, eat; i <= n; ++i) {
        eat = max(m - b[i], 0ll);
        add = min(min(m, a[i]) - eat, ans);
        ans -= add, eat += add;
        printf("%lld %lld\n", eat, m - eat);
      }
    }
  }
}
