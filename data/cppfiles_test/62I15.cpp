#include <bits/stdc++.h>
using namespace std;
const int mxn = 1001;
long long n, m, k, q;
long long a[mxn][mxn], dp[mxn][mxn][2];
void first(int x, int y, int z) {
  k += z * (dp[x][y][0] + dp[x][y][1] - a[x][y]);
}
void ff(int x, int y, int z) {
  if (x >= n || y >= m) return;
  first(x, y, -1), a[x][y] ^= z;
  for (int i = 0; i < 2; i++)
    dp[x][y][i] = a[x][y] * (dp[x - !i][y - i][!i] + 1);
  first(x, y, 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ff(i, j, 1);
    }
  while (q--) {
    int x, y;
    cin >> x >> y;
    ff(x, y, 1);
    for (x++, y++; x <= n + 1 && y <= m + 1; x++, y++) {
      ff(x, y - 1, 0), ff(x - 1, y, 0), ff(x, y, 0);
    }
    cout << k << '\n';
  }
  return 0;
}
