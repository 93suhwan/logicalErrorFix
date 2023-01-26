#include <bits/stdc++.h>
int main() {
  int t, n, i, l;
  int a[200];
  scanf("%d", &t);
  while (t--) {
    l = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
      if (i == 0) {
        if (a[i] == 1) {
          l = l + 1;
        }
      } else {
        if (a[i] == 1) {
          l = l + 1;
          if (a[i - 1] == 1) {
            l = l + 4;
          }
        } else {
          if (a[i - 1] == 0) {
            l = -1;
            break;
          }
        }
      }
    }
    printf("%d\n", l);
  }
  return 0;
}
