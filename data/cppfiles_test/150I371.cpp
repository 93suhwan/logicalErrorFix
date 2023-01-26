#include <bits/stdc++.h>
int int_cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }
int main(int argc, char *argv[]) {
  int i, T, n, onec, twoc, q, r, ans;
  int cost[128];
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &n);
    onec = twoc = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &cost[i]);
      onec |= (cost[i] % 3) == 1;
      twoc |= (cost[i] % 3) == 2;
    }
    qsort(cost, n, sizeof(cost[0]), int_cmp);
    q = cost[n - 1] / 3;
    if (onec == 0 && twoc == 0)
      ans = q;
    else if (onec == 0 || twoc == 0)
      ans = q + 1;
    else {
      r = cost[n - 1] % 3;
      if (r == 0)
        ans = q + 1;
      else if (r == 2)
        ans = q + 2;
      else if (cost[0] == 1 || cost[n - 2] == cost[n - 1] - 1)
        ans = q + 2;
      else
        ans = q + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
