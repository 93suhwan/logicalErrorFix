#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N][N], p[N], q[N];
char st[N][N];
void solve() {
  int n, m, i, j, k, s = 2e9, t;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", st[i] + 1);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) a[i][j] = a[i - 1][j] + st[i][j] - 48;
  for (i = 1; i <= n - 4; i++)
    for (j = i + 4; j <= n; j++) {
      t = 2e9;
      for (k = 1; k <= m; k++) {
        p[k] = (j - 1 - i) - (a[j - 1][k] - a[i][k]);
        q[k] = (j - 1 - i) - p[k] + (st[i][k] == 48) + (st[j][k] == 48);
        if (k > 3)
          t = min(t, p[k - 3] + q[k - 2] + q[k - 1]), s = min(s, t + p[k]);
        t += q[k];
      }
    }
  printf("%d\n", s);
}
int main() {
  int __;
  for (scanf("%d", &__); __--;) solve();
}
