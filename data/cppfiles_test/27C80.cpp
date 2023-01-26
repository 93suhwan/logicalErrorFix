#include <bits/stdc++.h>
using namespace std;
int a, b, d, c, f, e, ek, n, m, k, s, bj, c1, c2, c3, max1, min1;
char sz[100010], sz2[100010];
int main() {
  scanf("%d", &k);
  while (k--) {
    scanf("%s", sz);
    scanf("%s", sz2);
    n = strlen(sz);
    m = strlen(sz2);
    e = n - 1;
    f = m - 1;
    while (e >= 0 && f >= 0) {
      if (sz[e] == sz2[f]) {
        e--;
        f--;
      } else
        e -= 2;
    }
    if (f == -1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
