#include <bits/stdc++.h>
using namespace std;
inline int safeMod(int x, int p) { return (x + p) % p; }
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m, k;
int main() {
  int _ = 1;
  while (_--) {
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
    for (int i = 0; i < k; i++) {
      int col;
      scanf("%d", &col);
      col--;
      int row = 0;
      while (row < n && col < m) {
        if (g[row][col] == 1)
          g[row][col++] = 2;
        else if (g[row][col] == 2)
          g[row++][col] = 2;
        else if (g[row][col] == 3)
          g[row][col--] = 2;
      }
      cout << col + 1 << ' ';
    }
  }
  return 0;
}
