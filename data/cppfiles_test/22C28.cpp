#include <bits/stdc++.h>
#pragma optimize(3)
using namespace std;
int t[200005], x[200005], y[200005], n, m, a;
int u[200005], ans;
int v[500][500];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int sq = sqrt(m);
  for (int i = 1; i <= m; i++) {
    int op;
    scanf("%d%d", &op, &a);
    if (op == 1) {
      u[a] = i;
      int r = x[a] + y[a];
      if (r > sq) {
        for (int j = i + x[a]; j <= m; j += r) {
          t[j]++;
          if (j + y[a] <= m) t[j + y[a]]--;
        }
      } else {
        v[r][i % r]--;
        ans++;
        v[r][(i + x[a]) % r]++;
      }
    } else {
      int r = x[a] + y[a];
      int k = u[a];
      if ((i - k) % r > x[a] || (i - k) % r == 0) {
        ans--;
      }
      if (r > sq) {
        for (int j = k + x[a]; j <= m; j += r) {
          t[j]--;
          if (j + y[a] <= m) t[j + y[a]]++;
        }
      } else {
        v[r][k % r]++;
        v[r][(k + x[a]) % r]--;
      }
      u[a] = 0;
    }
    for (int j = 1; j * j <= m; j++) ans += v[j][i % j];
    ans += t[i];
    printf("%d\n", ans);
  }
  return 0;
}
