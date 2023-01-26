#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b, b + n);
    int r = n - 1;
    int f = 0;
    for (int i = 0; i <= r; i++) {
      if (b[i] != i + 1 || b[i] <= 2 * (i + 1)) {
        f = 1;
        break;
      }
    }
    if (f) {
      printf("NO");
    } else {
      printf("YES");
    }
    printf("\n");
  }
  return 0;
}
