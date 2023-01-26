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
    long long now = 0, ans = 0;
    for (int i = 62; i >= 0; i--) {
      now += (1ll << i);
      if (check(now) >= h) now -= (1ll << i);
    }
    printf("%lld\n", now + 1);
  }
  return 0;
}
