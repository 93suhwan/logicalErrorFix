#include <bits/stdc++.h>
int int_cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }
int main(int argc, char *argv[]) {
  int i, T, n, onec, twoc, hasone, m, ans;
  int cost[128];
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &n);
    hasone = onec = twoc = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &cost[i]);
      hasone |= cost[i] == 1;
      onec += (cost[i] % 3) == 1;
      twoc += (cost[i] % 3) == 2;
    }
    qsort(cost, n, sizeof(cost[0]), int_cmp);
    m = cost[n - 1];
    ans = m / 3;
    if (onec > 0 || twoc > 0)
      if (m % 3 == 0)
        ans += 1;
      else if (m % 3 == 1) {
        if (hasone && twoc > 0)
          ans += 2;
        else if (twoc > 0 && cost[n - 2] == m - 1)
          ans += 2;
        else
          ans += 1;
      } else
        ans += ((onec > 0) ? 2 : 1);
    printf("%d\n", ans);
  }
  return 0;
}
