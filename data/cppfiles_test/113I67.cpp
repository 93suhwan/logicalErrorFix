#include <bits/stdc++.h>
const int N = 200010;
int n, m, t;
long long s, x, y, ans, a[N];
inline int min(int x, int y) {
  if (x == -1) return y;
  if (y == -1) return x;
  return x < y ? x : y;
}
inline int max(int x, int y) { return x > y ? x : y; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i), s += a[i];
  std::sort(a + 1, a + n + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld", &x, &y), ans = -1;
    t = std::lower_bound(a + 1, a + n + 1, x) - a;
    if (t > 1) ans = min(ans, x - a[t - 1] + max(y - s + a[t - 1], 0));
    if (t <= n) ans = min(ans, max(y - s + a[t], 0));
    printf("%lld\n", ans);
  }
  return 0;
}
