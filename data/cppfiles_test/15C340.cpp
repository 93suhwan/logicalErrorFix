#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  char a[n][m];
  bool b[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '*') {
        b[i][j] = 0;
      } else {
        b[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        int d = 0;
        while (1) {
          int t = d + 1;
          int x1 = i - t, y1 = j - t, x2 = i - t, y2 = j + t;
          if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 < m && a[x1][y1] == '*' &&
              a[x2][y2] == '*') {
            d++;
          } else {
            break;
          }
        }
        if (d >= k) {
          while (d >= 0) {
            b[i - d][j - d] = 1;
            b[i - d][j + d] = 1;
            d--;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == 0) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
