#include <bits/stdc++.h>
using namespace std;
const int mxn = 110;
int i, j, k;
int x, y, z, xx, xy, xz, yx, yy, yz;
int m, n, p;
char a[mxn];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", a);
    m = strlen(a);
    if (a[0] != a[m - 1]) {
      a[0] = a[m - 1];
    }
    printf("%s\n", a);
  }
  return 0;
}
