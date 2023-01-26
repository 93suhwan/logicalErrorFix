#include <bits/stdc++.h>
using namespace std;
int t, n;
long long h, a[105] = {0};
long long check(long long x) {
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) ans += min(x, a[i + 1] - a[i]);
  return ans + x;
}
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%lld", &n, &h);
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &a[j]);
    }
    long long l = 1, r = h, mid, ans = 0;
    while (l < r) {
      mid = l + (r - l) / 2;
      long long che = check(mid);
      if (che >= h)
        r = ans = mid;
      else
        l = mid + 1;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
