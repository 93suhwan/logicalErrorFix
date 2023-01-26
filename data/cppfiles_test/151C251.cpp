#include <bits/stdc++.h>
int q;
int fa[500005];
int cnt, ans[500005];
struct Op {
  int tp;
  int x, y;
} op[500005];
int main() {
  for (int i = 1; i <= 500000; i++) fa[i] = i;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int tp;
    scanf("%d", &tp);
    op[i].tp = tp;
    if (tp == 1)
      scanf("%d", &op[i].x);
    else
      scanf("%d%d", &op[i].x, &op[i].y);
  }
  for (int i = q; i >= 1; i--) {
    if (op[i].tp == 2)
      fa[op[i].x] = fa[op[i].y];
    else
      ans[++cnt] = fa[op[i].x];
  }
  for (int i = cnt; i >= 1; i--) printf("%d%c", ans[i], " \n"[i == 1]);
  return 0;
}
