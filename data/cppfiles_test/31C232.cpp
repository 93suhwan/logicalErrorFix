#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    if ((n & 1)) {
      if (a[1] + a[2] != 0)
        printf("%d %d %d ", -a[3], -a[3], a[2] + a[1]);
      else if (a[1] + a[3] != 0)
        printf("%d %d %d ", -a[2], a[1] + a[3], -a[2]);
      else
        printf("%d %d %d ", a[3] + a[2], -a[1], -a[1]);
      for (int i = 4; i + 1 <= n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
    } else {
      for (int i = 1; i + 1 <= n; i += 2) printf("%d %d ", a[i + 1], -a[i]);
    }
    printf("\n");
  }
  return 0;
}
