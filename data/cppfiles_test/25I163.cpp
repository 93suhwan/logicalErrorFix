#include <bits/stdc++.h>
using namespace std;
int a, b, d, c, f, e, ek, n, m, k, s, bj, c1, c2, c3, max1, min1;
char sz[510], sz2[510];
int main() {
  scanf("%d", &k);
  while (k--) {
    scanf("%s", sz);
    scanf("%s", sz2);
    bj = 0;
    n = strlen(sz);
    m = strlen(sz2);
    for (a = 0; a < n; ++a) {
      e = a;
      f = 0;
      if (sz[a] != sz2[0]) continue;
      while (e < n && sz[e] == sz2[f] && f < m) {
        e++;
        f++;
      }
      e -= 2;
      while (e >= 0 && sz[e] == sz2[f] && f < m) {
        e--;
        f++;
      }
      if (f == m) {
        bj = 1;
        break;
      }
    }
    if (bj)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
