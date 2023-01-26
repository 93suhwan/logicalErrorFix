#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int main() {
  int t, m, bj, tt = 1000000000;
  scanf("%d", &t);
  while (t--) {
    tt = 1000000000;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
      a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
      b[i] += b[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      if (tt > max(a[m] - a[i], b[i - 1])) {
        tt = max(a[m] - a[i], b[i - 1]);
      }
    }
    printf("%d\n", tt);
  }
  return 0;
}
