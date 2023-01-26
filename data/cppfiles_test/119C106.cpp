#include <bits/stdc++.h>
int main() {
  int n, l;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int b = 0;
    scanf("%d", &l);
    int a[l];
    for (int j = 0; j < l; j++) {
      scanf("%d", &a[j]);
      b += a[j];
    }
    if (b % l == 0)
      printf("0\n");
    else
      printf("1\n");
  }
}
