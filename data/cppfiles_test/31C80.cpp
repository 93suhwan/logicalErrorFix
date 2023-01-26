#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n % 2 == 0) {
      for (int i = 1; i <= n; i += 2) {
        printf("%d %d ", -1 * a[i + 1], a[i]);
      }
      printf("\n");
    } else {
      if (a[2] + a[3] != 0) {
        printf("%d %d %d ", a[2] + a[3], -1 * a[1], -1 * a[1]);
      } else {
        printf("%d %d %d ", a[2] - a[3], -1 * a[1], a[1]);
      }
      for (int i = 4; i <= n; i += 2) {
        printf("%d %d ", -1 * a[i + 1], a[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
