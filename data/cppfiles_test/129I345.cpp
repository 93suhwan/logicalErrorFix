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
    int f = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] != (i + 1)) {
        if (b[i] - (i + 1) <= (i + 1)) {
          f = 1;
          break;
        } else
          c += 1;
      }
    }
    if (f) {
      printf("-1");
    } else {
      printf("%d", c);
    }
    printf("\n");
  }
  return 0;
}
