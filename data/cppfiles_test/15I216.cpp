#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int mymax = 1e18;
const long long int mymin = -1e18;
const double PIE = 3.1415926536;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, d, k, ti, tj, tmp;
  bool allvis, ans;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    char a[n][m];
    int vis[n][m];
    ans = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        vis[i][j] = 0;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      for (int j = 1; j <= (m - 2); j++) {
        if ((a[i][j] == '*') && (a[i - 1][j - 1] == '*') &&
            (a[i - 1][j + 1] == '*')) {
          vis[i][j] = 1;
          allvis = true;
          d = 0;
          ti = i - 1;
          tj = j;
          tmp = 1;
          while ((ti >= 0) && ((tj - tmp) >= 0) && ((tj + tmp) < m) &&
                 (a[ti][tj - tmp] == '*') && (a[ti][tj + tmp] == '*')) {
            d++;
            if ((!vis[ti][tj - tmp]) or (!vis[ti][tj + tmp])) {
              allvis = false;
            }
            vis[ti][tj - tmp] = vis[ti][tj + tmp] = 1;
            tmp++;
            ti--;
          }
          if ((!allvis) && (d < k)) {
            ans = false;
            break;
          }
        }
      }
      if (!ans) {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((a[i][j] == '*') && !vis[i][j]) {
          ans = false;
          break;
        }
      }
    }
    cout << ((ans) ? "YES" : "NO") << "\n";
  }
  return 0;
}
