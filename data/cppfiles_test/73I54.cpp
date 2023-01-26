#include <bits/stdc++.h>
int main() {
  int t, n, i, k = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int kul = 0;
    for (i = 0; i < n; i++) {
      int t = a[i];
      int j = a[i + 1];
      if (a[i] > a[i + 1]) {
        a[i] = j;
        a[i + 1] = t;
        kul++;
      }
    }
    if (kul != 0) {
      printf("%d\n", kul + 1);
    } else {
      printf("%d\n", kul);
    }
  }
  return 0;
}
