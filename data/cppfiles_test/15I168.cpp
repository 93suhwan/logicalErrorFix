#include <bits/stdc++.h>
using namespace std;
long long md = 1e9 + 7;
const long long inf = 1e17;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case = 1;
  cin >> test_case;
  while (test_case--) {
    long long i, j, n, k = 0, m = 0;
    cin >> n >> m >> k;
    char a[n][m];
    long long vis[n][m];
    memset(vis, 0, sizeof(vis));
    long long z = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    i = n - 1;
    bool ok = true;
    while (i >= 0) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == '*') {
          bool cb = true;
          if (vis[i][j] == 1) {
            cb = false;
          }
          long long l = i - 1, r = j - 1, g = i - 1, h = j + 1, cnt = 0;
          bool mk = false;
          while (l >= 0 && r >= 0 && g >= 0 && h < m) {
            if (a[l][r] != '*' || a[g][h] != '*') {
              break;
            }
            cnt++;
            mk = true;
            vis[l][r] = 1;
            vis[g][h] = 1;
            l--;
            r--;
            g--;
            h++;
          }
          if (mk) {
            vis[i][j] = 1;
          }
          if (cb == true && mk && cnt < k) {
            ok = false;
          }
        }
      }
      i--;
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == '*' && vis[i][j] == 0) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
