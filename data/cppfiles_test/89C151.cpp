#include <bits/stdc++.h>
int main() {
  int x, y, z, i, j, k, a, b, c, n, m, t, mat[100100];
  scanf("%d", &t);
  while (t--) {
    c = 0;
    scanf("%d", &n);
    for (x = 0; x < n; x++) scanf("%d", &mat[x]);
    for (x = 0; x < n; x++) {
      if (mat[x] % (x + 2))
        continue;
      else {
        for (y = 0; y < x; y++)
          if (mat[x] % (x + 2 - y - 1)) break;
        if (y == x) {
          puts("NO");
          break;
        }
      }
    }
    if (x == n) puts("YES");
  }
  return 0;
}
