#include <bits/stdc++.h>
using namespace std;
int f[100000 + 5][2], n, T, a[100000 + 5], mx, sum;
bool check(int md) {
  int dir = 1, dx = 0;
  for (int i = 1; i <= n; i++) {
    if (dx < 0 || dx > md) return 0;
    if (dir == 1) {
      if (dx + a[i] > md)
        dx -= a[i], dir = -1;
      else
        dx += a[i];
    }
    if (dir == -1) {
      if (dx - a[i] < 0)
        dx += a[i], dir = 1;
      else
        dx -= a[i];
    }
  }
  if (dx < 0 || dx > md) return 0;
  return 1;
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), mx = sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]), sum += a[i];
    }
    int l = mx, r = sum, ans = mx;
    while (l < r) {
      int md = (l + r) >> 1;
      if (check(md))
        ans = md, r = md;
      else
        l = md + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
