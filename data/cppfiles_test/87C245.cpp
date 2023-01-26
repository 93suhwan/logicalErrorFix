#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    pair<int, int> b[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        b[i][j] = {a[i][j], 0};
      }
    }
    for (int i = 0; i < n; i++) {
      sort(b[i], b[i] + m);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m - 1; k++) {
          if ((b[i][k].first == a[i][j] && b[i][k + 1].first > a[i][j]) ||
              (b[i][k].first == a[i][j] && b[i][k + 1].first == a[i][j] &&
               b[i][k + 1].second == 1)) {
            b[i][k].second = 1;
            break;
          }
          res += b[i][k].second;
        }
        if (a[i][j] == b[i][m - 1].first) b[i][m - 1].second = 1;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
