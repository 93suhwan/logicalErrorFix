#include <bits/stdc++.h>
int analisa(int a[], int n) {
  int j;
  for (j = 0; j < n - 1; j++) {
    if (a[j] > a[j + 1]) {
      return 1;
    }
  }
  return 0;
}
int main() {
  int t, n, i, j;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int t = 0, y = 0, k = 0, kul = 0;
    k = 0;
    int g = n;
    int u = n - 1;
    while (1) {
      if (analisa(a, n) != 1) {
        break;
      }
      if (kul % 2 != 0) {
        for (i = 1; i < n; i += 2) {
          t = a[i];
          y = a[i + 1];
          if (a[i] > a[i + 1]) {
            a[i] = y;
            a[i + 1] = t;
          }
        }
      } else {
        for (i = 0; i < n - 1; i += 2) {
          t = a[i];
          y = a[i + 1];
          if (a[i] > a[i + 1]) {
            a[i] = y;
            a[i + 1] = t;
          }
        }
      }
      kul++;
    }
    printf("%d\n", kul);
  }
  return 0;
}
