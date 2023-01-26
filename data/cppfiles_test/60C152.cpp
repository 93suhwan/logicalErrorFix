#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, min;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      if (i == 0) {
        min = arr[0];
      } else {
        min = min & arr[i];
      }
    }
    printf("%d\n", min);
  }
  return 0;
}
