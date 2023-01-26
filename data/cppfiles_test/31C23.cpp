#include <bits/stdc++.h>
using namespace std;
int n, k, f[1 << 19], mx[1 << 19], mn[1 << 19];
const int inf = 1 << 25;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 1 << k; i++) f[i] = mn[i] = inf, mx[i] = -inf;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    mx[x] = mn[x] = 0;
  }
  for (int i = 0; i < k; i++)
    for (int x = 0; x < 1 << k; x++)
      if (x & (1 << i)) {
        int y = x ^ (1 << i);
        f[x] = f[y] = min(f[x], f[y]);
        f[x] = min(f[x], mn[y] - mx[x] + (1 << i));
        f[y] = min(f[y], mn[x] - mx[y] + (1 << i));
        int mnx = mn[x], mny = mn[y], mxx = mx[x], mxy = mx[y];
        mn[x] = min(mnx, mny + (1 << i));
        mn[y] = min(mny, mnx + (1 << i));
        mx[x] = max(mxx, mxy + (1 << i));
        mx[y] = max(mxy, mxx + (1 << i));
      }
  for (int i = 0; i < 1 << k; i++) printf("%d ", f[i]);
}
