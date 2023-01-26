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
    int xx = row, yy = col;
    while (row != n) {
      int x = row, y = col;
      if (a[row][col] == 1) col++;
      if (a[row][col] == 2) row++;
      if (a[row][col] == 3) col--;
      a[x][y] = 2;
    }
    a[xx][yy] = 2;
    a[row][col] = 2;
    cout << col << ' ';
  }
  return 0;
}
