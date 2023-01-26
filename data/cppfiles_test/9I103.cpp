#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const double eps = 1e-6;
int n, m, k;
int G[maxn][maxn];
int walk(int &x, int &y) {
  int dir = G[x][y];
  G[x][y] = 2;
  switch (dir) {
    case 1:
      y++;
      break;
    case 2:
      x++;
      break;
    case 3:
      y--;
      break;
    default:
      break;
  }
  if (y < 1 || y > m || x > n) return 1;
  return 0;
}
void drop(int r, int c) {
  while (!walk(r, c)) {
  }
  cout << c << " ";
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> G[i][j];
  for (int i = 1; i <= k; i++) {
    int c;
    if (k >= n + 5) {
      cout << 1 << " ";
      continue;
    }
    cin >> c;
    drop(1, c);
  }
  return 0;
}
