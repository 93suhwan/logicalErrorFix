#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  int i, T, n, cost, onec, twoc, hasone, m, ans;
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d", &n);
    hasone = onec = twoc = m = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &cost);
      hasone |= cost == 1;
      onec += (cost % 3) == 1;
      twoc += (cost % 3) == 2;
      if (m < cost) m = cost;
    }
    if (onec == 0 && twoc == 0)
      ans = m / 3;
    else if (m % 3 == 0)
      ans = m / 3 + 1;
    else if (m % 3 == 1)
      ans = m / 3 + ((hasone && twoc > 0) ? 2 : 1);
    else
      ans = m / 3 + ((onec > 0) ? 2 : 1);
    printf("%d\n", ans);
  }
  return 0;
}
