#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int m;
  int k;
  cin >> n >> m >> k;
  int a[n][m];
  int i, j, l, p;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int b[k];
  for (i = 0; i < k; i++) cin >> b[i];
  for (int u = 0; u < k; u++) {
    int row = 0;
    int col = b[u] - 1;
    while (row < n) {
      p = a[row][col];
      a[row][col] = 2;
      if (p == 1) {
        col += 1;
      } else if (p == 2) {
        row += 1;
      } else if (p == 3) {
        col -= 1;
      }
    }
    cout << col + 1 << " ";
  }
}
