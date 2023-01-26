#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int rez[k], x, y;
  for (int i = 0; i < k; i++) {
    cin >> y;
    x = 1;
    while (x <= n) {
      if (a[x][y] == 2) {
        x++;
      } else if (a[x][y] == 1) {
        a[x][y] = 2;
        y++;
      } else {
        a[x][y] = 2;
        y--;
      }
    }
    cout << y << ' ';
  }
  return 0;
}
