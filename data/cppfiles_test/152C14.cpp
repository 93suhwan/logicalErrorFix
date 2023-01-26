#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int n, a[N], f[N][2][2], ans[N];
void clean(int x) {
  for (int i = (0); i <= (1); ++i)
    for (int j = (0); j <= (1); ++j) f[x][i][j] = inf;
}
int fx[N][2][2], fy[N][2][2];
void upd(int i, int j, int k, int px, int py, int x) {
  if (f[i][j][k] > x) f[i][j][k] = x, fx[i][j][k] = px, fy[i][j][k] = py;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, x, y, px, py, tx, ty;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = (1); i <= (n); ++i) cin >> a[i];
    clean(1);
    f[1][1][0] = f[1][1][1] = -inf;
    for (int i = (2); i <= (n); ++i) {
      clean(i);
      for (int k1 = (0); k1 <= (1); ++k1)
        for (int k2 = (0); k2 <= (1); ++k2) {
          x = (k1 ? -a[i - 1] : a[i - 1]);
          y = (k2 ? -a[i] : a[i]);
          for (int j1 = (0); j1 <= (1); ++j1) {
            if (f[i - 1][j1][k1] == inf) continue;
            if (x < y) {
              if (j1 == 0) {
                if (f[i - 1][j1][k1] > y)
                  upd(i, 0, k2, j1, k1, f[i - 1][j1][k1]);
                else
                  upd(i, 1, k2, j1, k1, x);
              } else
                upd(i, 1, k2, j1, k1, f[i - 1][j1][k1]);
            } else {
              if (j1 && y > f[i - 1][j1][k1]) upd(i, 0, k2, j1, k1, x);
            }
          }
        }
    }
    px = -1;
    py = -1;
    for (int j = (0); j <= (1); ++j)
      for (int k = (0); k <= (1); ++k)
        if (f[n][j][k] != inf) {
          px = j;
          py = k;
          break;
        }
    if (px == -1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = (n); i >= (1); --i) {
      ans[i] = (py ? -a[i] : a[i]);
      tx = fx[i][px][py];
      ty = fy[i][px][py];
      px = tx;
      py = ty;
    }
    for (int i = (1); i <= (n); ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}
