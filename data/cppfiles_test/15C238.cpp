#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int mymax = 1e18;
const long long int mymin = -1e18;
const double PIE = 3.1415926536;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, m, d, k, ti, lef, rit;
  bool ans;
  vector<pair<int, int> > cent;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    char a[n][m];
    int vis[n][m];
    cent.clear();
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
          d = 0;
          ti = i - 1;
          lef = j - 1;
          rit = j + 1;
          while ((ti >= 0) && (lef >= 0) && (rit < m) && (a[ti][lef] == '*') &&
                 (a[ti][rit] == '*')) {
            d++;
            ti--;
            lef--;
            rit++;
          }
          if (d >= k) {
            cent.push_back({i, j});
          }
        }
      }
    }
    for (auto it : cent) {
      vis[it.first][it.second] = 1;
      ti = it.first - 1;
      lef = it.second - 1;
      rit = it.second + 1;
      while ((ti >= 0) && (lef >= 0) && (rit < m) && (a[ti][lef] == '*') &&
             (a[ti][rit] == '*')) {
        vis[ti][lef] = vis[ti][rit] = 1;
        ti--;
        lef--;
        rit++;
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
