#include <bits/stdc++.h>
using namespace std;
const int N = 110, mod = 1e9 + 7, p = 31, p2 = 37;
int a[N][N], vis[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(vis, 0, sizeof vis);
    int n, m, k;
    cin >> n >> m >> k;
    char c;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> c, a[i][j] = c == '*';
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!a[i][j]) continue;
        int cnt = 0, j1 = j - 1, j2 = j + 1;
        for (int ii = i - 1; ii >= 1 && j1 >= 1 && j2 <= m; ii--, j1--, j2++) {
          if (!a[ii][j1] || !a[ii][j2]) break;
          cnt++;
        }
        if (cnt >= k) {
          vis[i][j] = 1;
          int j1 = j - 1, j2 = j + 1;
          for (int ii = i - 1; ii >= 1 && j1 >= 1 && j2 <= m;
               ii--, j1--, j2++) {
            if (!a[ii][j1] || !a[ii][j2]) break;
            vis[ii][j1] = vis[ii][j2] = 1;
          }
        }
      }
    }
    int ok = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (a[i][j]) ok &= vis[i][j];
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
