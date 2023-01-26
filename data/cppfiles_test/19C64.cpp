#include <bits/stdc++.h>
using namespace std;
int n, T, a[100000 + 5], mx, sum;
bitset<4000> bt, ln;
bool check(int md) {
  for (int i = 0; i < 4000; i++) bt[i] = 0, ln[i] = 0;
  for (int i = 0; i < md; i++) bt[i] = 1, ln[i] = 1;
  for (int i = n; i; --i) bt = ((bt >> a[i]) | (bt << a[i])), bt &= ln;
  int ret = 0;
  for (int i = 0; i < md; i++)
    if (bt[i]) return 1;
  return 00;
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), mx = sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]), sum += a[i];
    }
    int l = mx, r = 2 * mx, ans = mx;
    while (l <= r) {
      int md = (l + r) >> 1;
      if (check(md))
        ans = md, r = md - 1;
      else
        l = md + 1;
    }
    printf("%d\n", --l);
  }
  return 0;
}
