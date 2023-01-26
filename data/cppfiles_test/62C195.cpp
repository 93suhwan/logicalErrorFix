#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, x, y = 0;
  scanf("%d", &t);
  for (int ii = 1; ii <= t; ii++) {
    scanf("%d", &n);
    y = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (x != y && y != 2) {
        printf("%d ", n + 1);
        y = 2;
        printf("%d ", i);
      } else
        printf("%d ", i);
    }
    if (y == 0) printf("%d ", n + 1);
    printf("\n");
  }
  return 0;
}
