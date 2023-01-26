#include <bits/stdc++.h>
using std::min;
int a[11], p10[11];
int main() {
  int T, n, k;
  long long res;
  scanf("%d", &T);
  for (int i = 0, j = 1; i <= 9; ++i, j *= 10) p10[i] = j;
  while (T--) {
    res = 0;
    scanf("%d%d", &n, &k);
    ++k;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i < n; ++i) {
      int max_use = p10[a[i + 1] - a[i]] - 1;
      int use = min(k, max_use);
      res += 1ll * use * p10[a[i]];
      if ((k -= use) == 0) break;
    }
    if (k) res += 1ll * p10[a[n]] * k;
    printf("%lld\n", res);
  }
  return 0;
}
