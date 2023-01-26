#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, nw, l, r, p, b[1005][1005], c[1005][1005];
char a[1005][1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    nw = 0;
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    if (!k) {
      cout << "YES" << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = k + 1; i <= n; i++) {
      for (int j = k + 1; j <= m - k; j++)
        if (a[i][j] == '*') b[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (b[i][j]) {
          p = i;
          r = l = j;
          nw = 0;
          while (1) {
            p--;
            r--;
            l++;
            if (a[p][r] == '*' and a[p][l] == '*')
              nw++;
            else
              break;
          }
          if (nw >= k) {
            p = i;
            r = l = j;
            c[i][j] = 1;
            while (1) {
              p--;
              r--;
              l++;
              if (a[p][r] == '*' and a[p][l] == '*')
                c[p][r] = c[p][l] = 1;
              else
                break;
            }
          }
        }
      }
    }
    nw = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        if (a[i][j] == '*' and !c[i][j]) nw = 1;
    }
    if (nw)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
