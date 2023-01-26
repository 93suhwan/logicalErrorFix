#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 5][m + 5], row, col;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    row = 1;
    cin >> col;
    while (row != n + 1) {
      int x = row, y = col;
      if (a[row][col] == 1)
        col++;
      else if (a[row][col] == 2)
        row++;
      else if (a[row][col] == 3)
        col--;
      a[x][y] = 2;
    }
    cout << col << ' ';
  }
  return 0;
}
