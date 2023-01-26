#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], f[1005][1005], ans;
int calc(int x, int y, int dx, int dy, int type) {
  int cnt = 0;
  if (type == 0) {
    while (x - dx >= 1 && y - dy >= 1) {
      x -= dx, y -= dy;
      if (!a[x][y]) break;
      ++cnt;
      if (dx == 1)
        dy = 1, dx = 0;
      else
        dy = 0, dx = 1;
    }
  } else {
    while (x + dx <= n && y + dy <= m) {
      x += dx, y += dy;
      if (!a[x][y]) break;
      ++cnt;
      if (dx == 1)
        dy = 1, dx = 0;
      else
        dy = 0, dx = 1;
    }
  }
  return cnt;
}
signed main() {
  int q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) a[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans += 1 + calc(i, j, 0, 1, 1) + calc(i, j, 1, 0, 1);
  while (q--) {
    int i, j;
    cin >> i >> j;
    int sum = (1 + calc(i, j, 0, 1, 1)) * (1 + calc(i, j, 1, 0, 0)) +
              (1 + calc(i, j, 1, 0, 1)) * (1 + calc(i, j, 0, 1, 0)) - 1;
    if (a[i][j])
      ans -= sum;
    else
      ans += sum;
    a[i][j] ^= 1;
    cout << ans << "\n";
  }
}
