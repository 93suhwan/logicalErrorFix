#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int g[N][N], f[N][N];
inline int get(int a, int b, int c, int d) {
  return f[a][b] + f[c - 1][d - 1] - f[a][d - 1] - f[c - 1][b];
}
inline void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char s;
      cin >> s;
      g[i][j] = s - '0';
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + g[i][j];
    }
  }
  int ans = 10000;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      for (int i = x + 4; i <= n; i++) {
        for (int j = y + 3; j <= m; j++) {
          int suml = g[x][y] + g[i][y], sumr = g[i][j] + g[x][j];
          int out = get(i, j, x, y), ins = get(i - 1, j - 1, x + 1, y + 1);
          int r = get(i, j, x, j) - sumr;
          ans = min(ans, ins + 2 * (i + j - x - y - 2) -
                             (out - ins - suml - sumr - r));
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
