#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j, k, n, m, x, y;
  cin >> n >> m >> k;
  vector<vector<int>> mat(n, vector<int>(m)), jump(n, vector<int>(m, -1));
  vector<int> col(k);
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> mat[i][j];
  for (i = 0; i < k; ++i) cin >> col[i], --col[i];
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mat[i][j] == 2 && jump[i][j] == -1) {
        for (y = i; y < n; ++y)
          if (mat[y][j] != 2) break;
        x = y;
        for (y = i; y < n; ++y) {
          if (mat[y][j] == 2)
            jump[y][j] = x;
          else
            break;
        }
      }
    }
  }
  for (i = 0; i < k; ++i) {
    x = 0;
    y = col[i];
    while (true) {
      if (x == n) break;
      if (mat[x][y] == 1) {
        mat[x][y] = 2;
        if (x + 1 < n && jump[x + 1][y] != -1)
          jump[x][y] = jump[x + 1][y];
        else
          jump[x][y] = x + 1;
        y++;
      } else if (mat[x][y] == 3) {
        mat[x][y] = 2;
        if (x + 1 < n && jump[x + 1][y] != -1)
          jump[x][y] = jump[x + 1][y];
        else
          jump[x][y] = x + 1;
        y--;
      } else {
        while (jump[x][y] != -1) {
          x = jump[x][y];
          if (x == n) break;
        }
      }
    }
    cout << y + 1 << " ";
  }
  cout << "\n";
  return 0;
}
