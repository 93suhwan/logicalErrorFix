#include <bits/stdc++.h>
int main() {
  int i, j, n, t, a[100], mov = 0, d = 0;
  scanf("%d", &t);
  while (t > 0) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = n - 1; i >= 0; i--) {
      if (a[i] != 0) {
        d++;
      }
      if (a[i] != 0 && i != 0 && d != 1) {
        mov = mov + a[i] + 1;
      }
      if (a[i] != 0 && i == 0 || d == 1) {
        mov = mov + a[i];
      }
    }
    printf("%d\n", mov);
    t--;
  }
  return 0;
}
