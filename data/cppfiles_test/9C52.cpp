#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1001][1001];
int c[100001];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) {
    int x = 1, y = c[i];
    while (x <= n) {
      if (a[x][y] == 1)
        a[x][y] = 2, y++;
      else if (a[x][y] == 3)
        a[x][y] = 2, y--;
      else
        x++;
    }
    cout << y << " ";
  }
  cout << endl;
  return 0;
}
