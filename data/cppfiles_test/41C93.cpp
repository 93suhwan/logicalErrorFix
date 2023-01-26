#include <bits/stdc++.h>
using namespace std;
int n, k;
int ans[1005][1005];
int main() {
  int i, j, sz, l, r, color, mx = 0;
  scanf("%d%d", &n, &k);
  for (sz = 1, color = 1; sz <= n; sz *= k, color++) {
    for (i = 1; i <= n; i += sz) {
      r = min(n, i + sz * k - 1);
      for (j = i; j <= i + sz - 1; j++) {
        for (l = i + sz; l <= r; l++) {
          ans[j][l] = color;
          mx = max(mx, color);
        }
      }
    }
  }
  printf("%d\n", mx);
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      printf("%d ", ans[i][j]);
    }
  }
  return 0;
}
