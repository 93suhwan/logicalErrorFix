#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int n, a[N], f[N][2], fro[N][2], ans[N];
void upd(int i, int j, int k, int x) {
  if (f[i][j] == inf) f[i][j] = x, fro[i][j] = k;
  if (f[i][j] > x) f[i][j] = x, fro[i][j] = k;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, j, x, y, bf;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = (1); i <= (n); ++i) cin >> a[i];
    f[1][0] = f[1][1] = -inf;
    for (int i = (2); i <= (n); ++i) {
      f[i][0] = f[i][1] = inf;
      j = 1;
      x = -a[i];
      for (int k = (0); k <= (1); ++k) {
        if (f[i - 1][k] == inf) continue;
        y = (k ? -a[i - 1] : a[i - 1]);
        bf = (f[i - 1][k] != y ? y : (fro[i - 1][k] ? -a[i - 2] : a[i - 2]));
        if (x > f[i - 1][k]) {
          if (x > bf)
            upd(i, j, k, f[i - 1][k]);
          else
            upd(i, j, k, x);
        }
      }
      j = 0;
      x = a[i];
      for (int k = (0); k <= (1); ++k) {
        if (f[i - 1][k] == inf) continue;
        y = (k ? -a[i - 1] : a[i - 1]);
        bf = (f[i - 1][k] != y ? y : (fro[i - 1][k] ? -a[i - 2] : a[i - 2]));
        if (x > f[i - 1][k]) {
          if (x > bf)
            upd(i, j, k, f[i - 1][k]);
          else
            upd(i, j, k, x);
        }
      }
    }
    if (f[n][0] != inf)
      j = 0;
    else if (f[n][1] != inf)
      j = 1;
    else
      j = -1;
    if (j == -1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = (n); i >= (1); --i) {
      ans[i] = (j ? -a[i] : a[i]);
      j = fro[i][j];
    }
    for (int i = (1); i <= (n); ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}
