#include <bits/stdc++.h>
int main() {
  int i, h, c, n, m;
  int tc;
  scanf("%d", &tc);
  while (tc) {
    tc--;
    scanf("%d", &n);
    h = 1;
    c = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &m);
      if (h < 0) continue;
      if (m == 0) {
        c++;
        if (c == 2) {
          h = -1;
        }
      } else {
        if (c)
          h += 1;
        else if (i)
          h += 5;
        else
          h += 1;
        c = 0;
      }
    }
    printf("%d\n", h);
  }
  return 0;
}
