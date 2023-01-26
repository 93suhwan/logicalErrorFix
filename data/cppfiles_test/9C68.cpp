#include <bits/stdc++.h>
using namespace std;
void sol() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++)
    for (int ii = 1; ii <= m; ii++) cin >> a[i][ii];
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> y;
    x = 1;
    while (x != n + 1) {
      if (a[x][y] == 1)
        a[x][y] = 2, y++;
      else if (a[x][y] == 2)
        x++;
      else
        a[x][y] = 2, y--;
    }
    cout << y << " ";
  }
  cout << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  ;
  int tc = 1;
  while (tc--) sol();
  return 0;
}
