#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 555;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char c[maxn][maxn];
int res[maxn][maxn];
bool valid(int x, int y) { return (x > 0 && y > 0 && x <= n && y <= m); }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> c[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (c[i][j] == 'X') {
        int cnt = 0;
        for (int k = 0; k <= 3; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (!valid(x, y)) continue;
          cnt += (c[x][y] == '.');
        }
        if (cnt % 2) return cout << "NO\n", 0;
        res[i][j] = cnt / 2 * 5;
      }
  int tmp = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (c[i][j] == '.')
        res[i][j] = tmp;
      else if (valid(i - 1, j) && c[i - 1][j] == 'X')
        tmp = 5 - tmp;
    }
    tmp = 5 - tmp;
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cout << res[i][j] << " \n"[j == m];
  return 0;
}
