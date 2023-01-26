#include <bits/stdc++.h>
int main() {
  int i, j, n, t, a[2][105], count;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    count = 0;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
        if (i == 1) {
          if (a[i][j] == 1 && a[i - 1][j] == 1) {
            count++;
          }
        }
      }
    }
    if (count == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
