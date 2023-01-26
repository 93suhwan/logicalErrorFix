#include <bits/stdc++.h>
struct player {
  int a, b, xh;
} pl[100010];
int t, n, ans[100010];
bool cmp(player x, player y) { return x.a > y.a; }
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &pl[i].a), pl[i].xh = i;
    for (int i = 1; i <= n; ++i) scanf("%d", &pl[i].b);
    std::sort(pl + 1, pl + n + 1, cmp);
    for (int i = n; i >= 1; --i)
      if (pl[i].b >= pl[1].b) {
        for (int j = i; j >= 1; --j) ans[pl[j].xh] = 1;
        break;
      }
    for (int i = 1; i <= n; ++i) printf("%d", ans[i]);
    putchar('\n');
  }
  return 0;
}
