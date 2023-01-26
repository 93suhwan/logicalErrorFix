#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, x, y, z, p[100001], q[100001], pre[100001], a[100001], b = 300;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), pre[a[i]] = i;
  for (i = 1; i <= n; i++) {
    p[i] = i;
    for (j = 1; j <= b; j++) p[i] = a[p[i]];
  }
  while (m--) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) {
      swap(a[y], a[z]);
      pre[a[y]] = y;
      pre[a[z]] = z;
      q[0] = y;
      for (i = 1; i <= b; i++) q[i] = a[q[i - 1]];
      for (i = 1; i <= b; i++) y = pre[y], p[y] = q[b - i];
      q[0] = z;
      for (i = 1; i <= b; i++) q[i] = a[q[i - 1]];
      for (i = 1; i <= b; i++) z = pre[z], p[z] = q[b - i];
    }
    if (x == 2) {
      while (z >= b) z -= b, y = p[y];
      while (z) z--, y = a[y];
      printf("%d\n", y);
    }
  }
}
