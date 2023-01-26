#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    x = x - 1;
    int r = 0;
    int c = x;
    while (r != n && c != m) {
      if (a[r][c] == 1) {
        a[r][c] = 2;
        c = c + 1;
      } else {
        if (a[r][c] == 2) {
          a[r][c] = 2;
          r = r + 1;
        } else {
          if (a[r][c] == 3) {
            a[r][c] = 2;
            c = c - 1;
          }
        }
      }
    }
    cout << c + 1 << " ";
  }
}
