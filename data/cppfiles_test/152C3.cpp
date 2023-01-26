#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int INf = 0x7f7f7f7f;
int n, a[N], f[N][2], g[N][2];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      f[i][0] = f[i][1] = INf;
    }
    f[1][0] = f[1][1] = -INf;
    for (int i = 2; i <= n; i++) {
      if (a[i] > a[i - 1] && f[i][0] > f[i - 1][0]) {
        f[i][0] = f[i - 1][0];
        g[i][0] = 0;
      }
      if (a[i] > f[i - 1][0] && f[i][0] > a[i - 1]) {
        f[i][0] = a[i - 1];
        g[i][0] = 0;
      }
      if (a[i] > -a[i - 1] && f[i][0] > f[i - 1][1]) {
        f[i][0] = f[i - 1][1];
        g[i][0] = 1;
      }
      if (a[i] > f[i - 1][1] && f[i][0] > -a[i - 1]) {
        f[i][0] = -a[i - 1];
        g[i][0] = 1;
      }
      if (-a[i] > a[i - 1] && f[i][1] > f[i - 1][0]) {
        f[i][1] = f[i - 1][0];
        g[i][1] = 0;
      }
      if (-a[i] > f[i - 1][0] && f[i][1] > a[i - 1]) {
        f[i][1] = a[i - 1];
        g[i][1] = 0;
      }
      if (-a[i] > -a[i - 1] && f[i][1] > f[i - 1][1]) {
        f[i][1] = f[i - 1][1];
        g[i][1] = 1;
      }
      if (-a[i] > f[i - 1][1] && f[i][1] > -a[i - 1]) {
        f[i][1] = -a[i - 1];
        g[i][1] = 1;
      }
    }
    if (f[n][0] == INf && f[n][1] == INf) {
      printf("NO\n");
    } else {
      printf("YES\n");
      int u = f[n][0] == INf ? 1 : 0;
      for (int i = n; i >= 1; i--) {
        a[i] = u ? -a[i] : a[i];
        u = g[i][u];
      }
      for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
