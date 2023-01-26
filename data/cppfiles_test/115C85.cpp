#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    long long h;
    scanf("%d%lld", &n, &h);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    long long l = 1, r = 1e18, ans = 0;
    while (l <= r) {
      long long mid = l + r >> 1;
      long long now = 0;
      for (int i = 1; i < n; ++i) {
        if (a[i] + mid - 1 < a[i + 1]) {
          now += mid;
        } else
          now += a[i + 1] - a[i];
      }
      now += mid;
      if (now >= h) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    printf("%lld\n", ans);
  }
}
