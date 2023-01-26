#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  vector<vector<bool>> b(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  while (k--) {
    int c, r = 0;
    cin >> c;
    c--;
    while (1) {
      if (b[r][c]) {
        cout << c + 1 << " ";
        break;
      }
      if (a[r][c] == 1) {
        b[r][c] = true;
        a[r][c] = 2;
        c++;
      } else if (a[r][c] == 2) {
        b[r][c] = true;
        r++;
      } else if (a[r][c] == 3) {
        b[r][c] = true;
        a[r][c] = 2;
        c--;
      }
      if (r >= n) {
        cout << c + 1 << " ";
        break;
      } else if (c < 0) {
        cout << 1 << " ";
        break;
      } else if (c >= m) {
        cout << c << " ";
        break;
      }
    }
  }
}
