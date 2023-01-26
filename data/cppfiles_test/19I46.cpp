#include <bits/stdc++.h>
using namespace std;
int n, T, a[100000 + 5], mx, sum;
bitset<4000> bt, ln;
bool check(int md) {
  ln.reset();
  for (int i = 0; i < md; i++) bt.set(i), ln.set(i);
  for (int i = n; i; --i) {
    bt = (bt >> a[i]) | (bt << a[i]);
    bt &= ln;
  }
  return bt.any();
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
    printf("%d\n", --ans);
  }
  return 0;
}
