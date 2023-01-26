#include <bits/stdc++.h>
int main() {
  int n, l, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &l);
    int a[l];
    for (int j = 0; j < l; j++) {
      b = 0;
      scanf("%d", &a[j]);
      b += a[j];
    }
    if (b % l == 0) {
      printf("1");
      printf("\n");
    } else {
      printf("0\n");
      printf("\n");
    }
  }
}
