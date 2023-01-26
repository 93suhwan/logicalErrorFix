#include <bits/stdc++.h>
int a[107];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    int n, ans = 0;
    scanf("%d", &n);
    for (int j = 1, k = 1; j <= n; j++) {
      scanf("%d", &a[j]);
      if (a[j] <= k) {
        k++;
      } else {
        ans += a[j] - k;
        k = a[j] + 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
