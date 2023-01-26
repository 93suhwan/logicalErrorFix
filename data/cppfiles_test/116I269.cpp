#include <bits/stdc++.h>
int n, t, a, f[500005][2], ans;
void ad(int& x, const int y) {
  if (y >= 998244353)
    x += y - 998244353;
  else
    x += y;
  if (x >= 998244353) x -= 998244353;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a);
      if (a > i) continue;
      int f0 = a > 0 ? f[a - 1][0] : 0, f1 = a > 0 ? f[a - 1][1] : 0,
          f2 = f[a][0], f3 = f[a][1], f4 = f[a + 1][0], f5 = f[a + 1][1];
      ans = ((long long)ans + f0 + f1 + f2 + f4 + f5) % 998244353;
      ad(f[a + 2][0], f3);
      ad(f[a + 1][1], f5);
      ad(f[a + 1][0], f4 + f2);
      ad(f[a - 1][1], f2 + f1);
    }
    for (int i = 0; i <= n; ++i) f[i][0] = f[i][1] = 0;
    printf("%d\n", ans);
  }
}
