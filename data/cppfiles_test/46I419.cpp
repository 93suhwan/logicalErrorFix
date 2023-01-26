#include <bits/stdc++.h>
using namespace std;
int c[1005];
int main() {
  int n, i, j;
  long long ans = 0, s, m;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", c + i);
  for (i = 1; i <= 2 * (n / 2); i += 2) ans += min(c[i], c[i + 1]);
  for (i = 2; i < n; i += 2) {
    s = 0;
    m = 0;
    for (j = i + 1; j < n; j += 2) {
      s -= c[j - 1];
      if (s < m) m = s;
      s += c[j];
      if (s < m) m = s;
      if (c[i - 1] >= -m && c[j + 1] >= s - m)
        ans += min(c[i - 1] + max(0ll, m), c[j + 1] - s + max(0ll, m));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
