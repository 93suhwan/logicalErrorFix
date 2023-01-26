#include <bits/stdc++.h>
using namespace std;
int a[10010], b[10010];
int main() {
  int t, m, minn = 1000000000, bj, tt = 1000000000;
  scanf("%d", &t);
  while (t--) {
    minn = 1000000000, tt = 1000000000;
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
      if (a[i] + b[m] - b[i - 1] < minn ||
          a[i] + b[m] - b[i - 1] == minn && tt > max(a[m] - a[i], b[i - 1])) {
        bj = i;
        tt = max(a[m] - a[i], b[i - 1]);
      }
    }
    printf("%d\n", tt);
  }
  return 0;
}
