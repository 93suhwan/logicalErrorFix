#include <bits/stdc++.h>
using namespace std;
int n, m, t, a[405][405], f[405][405], b[405], c[405];
char x;
int get(int x, int y, int u, int v) {
  if (x > u || y > v) return 0;
  return (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1]);
}
int get2(int x, int y, int u, int v) {
  if (x > u || y > v) return 0;
  return (v - y + 1) * (u - x + 1) -
         (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        cin >> x;
        a[i][j] = x - '0';
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
      }
    int ans = 1e9;
    for (int i = 1; i <= m; ++i)
      for (int j = i + 4; j <= m; ++j) {
        int res = -1e9;
        for (int k = 1; k <= n; ++k) {
          b[k] = get2(i, 1, i, k) + get2(j, 1, j, k);
          c[k] = get(i + 1, 1, j - 1, k);
          if (k >= 4) {
            res = max(res,
                      b[k - 3] + c[k - 3] - get2(i + 1, k - 3, j - 1, k - 3));
            ans =
                min(ans, b[k - 1] + c[k - 1] - res + get2(i + 1, k, j - 1, k));
          }
        }
      }
    cout << ans << '\n';
  }
}
