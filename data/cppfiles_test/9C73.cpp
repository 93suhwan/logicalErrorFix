#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < k; i++) {
    int y;
    cin >> y;
    int curx = 0, cury = y - 1;
    while (curx < n) {
      int dir = a[curx][cury];
      a[curx][cury] = 2;
      if (dir == 1) cury++;
      if (dir == 2) curx++;
      if (dir == 3) cury--;
    }
    cout << cury + 1 << " ";
  }
}
