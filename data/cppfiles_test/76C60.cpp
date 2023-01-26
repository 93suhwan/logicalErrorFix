#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, x, y, v[N][N], a[N];
void solve() {
  bool f0 = 1, f1 = 1;
  for (int i = 1; i <= 5; i++)
    for (int j = i + 1; j <= 5; j++) f0 &= !v[a[i]][a[j]], f1 &= v[a[i]][a[j]];
  if (f0 || f1) {
    for (int i = 1; i <= 5; i++) printf("%d ", a[i]);
    exit(0);
  }
}
signed main() {
  scanf("%d%d", &n, &m), n = min(n, 50);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (x <= n && y <= n) v[x][y] = v[y][x] = 1;
  }
  for (a[1] = 1; a[1] <= n; a[1]++)
    for (a[2] = a[1] + 1; a[2] <= n; a[2]++)
      for (a[3] = a[2] + 1; a[3] <= n; a[3]++)
        for (a[4] = a[3] + 1; a[4] <= n; a[4]++)
          for (a[5] = a[4] + 1; a[5] <= n; a[5]++) solve();
  puts("-1");
  return 0;
}
