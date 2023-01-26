#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  long long n, m;
  cin >> n >> m;
  long long q;
  cin >> q;
  long long down[n][m][2];
  long long sum = 0;
  for (long long l = n - 1; l >= 0; --l) {
    for (long long i = m - 1; i >= 0; --i) {
      down[l][i][0] = 1;
      if (l + 1 < n) down[l][i][0] = down[l + 1][i][1] + 1;
      down[l][i][1] = 1;
      if (i + 1 < m) down[l][i][1] = down[l][i + 1][0] + 1;
      sum += down[l][i][0] + down[l][i][1];
    }
  }
  bool blocked[n][m];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      blocked[i][j] = false;
    }
  }
  long long open = n * m;
  for (long long k = 0; k < q; ++k) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    if (blocked[x][y]) {
      open++;
      long long xx = x;
      long long yy = y;
      long long type = 0;
      sum -= down[xx][yy][type];
      down[xx][yy][type] = 1;
      sum += down[xx][yy][type];
      while (xx >= 0 && yy >= 0 && ((xx == x && yy == y) || !blocked[xx][yy])) {
        if (type == 0) {
          sum -= down[xx][yy][type];
          if (xx + 1 < n) down[xx][yy][type] = down[xx + 1][yy][1 - type] + 1;
          sum += down[xx][yy][type];
          yy--;
        } else {
          sum -= down[xx][yy][type];
          if (yy + 1 < m) down[xx][yy][type] = down[xx][yy + 1][1 - type] + 1;
          sum += down[xx][yy][type];
          xx--;
        }
        type = 1 - type;
      }
      xx = x;
      yy = y;
      type = 1;
      sum -= down[xx][yy][type];
      down[xx][yy][type] = 1;
      sum += down[xx][yy][type];
      while (xx >= 0 && yy >= 0 && ((xx == x && yy == y) || !blocked[xx][yy])) {
        if (type == 0) {
          sum -= down[xx][yy][type];
          if (xx + 1 < n) down[xx][yy][type] = down[xx + 1][yy][1 - type] + 1;
          sum += down[xx][yy][type];
          yy--;
        } else {
          sum -= down[xx][yy][type];
          if (yy + 1 < m) down[xx][yy][type] = down[xx][yy + 1][1 - type] + 1;
          sum += down[xx][yy][type];
          xx--;
        }
        type = 1 - type;
      }
    } else {
      open--;
      long long xx = x;
      long long yy = y;
      long long type = 0;
      sum -= down[xx][yy][type];
      down[xx][yy][type] = 0;
      sum += down[xx][yy][type];
      while (xx >= 0 && yy >= 0 && ((xx == x && yy == y) || !blocked[xx][yy])) {
        if (type == 0) {
          sum -= down[xx][yy][type];
          if (xx != x || yy != y)
            if (xx + 1 < n) down[xx][yy][type] = down[xx + 1][yy][1 - type] + 1;
          sum += down[xx][yy][type];
          yy--;
        } else {
          sum -= down[xx][yy][type];
          if (xx != x || yy != y)
            if (yy + 1 < m) down[xx][yy][type] = down[xx][yy + 1][1 - type] + 1;
          sum += down[xx][yy][type];
          xx--;
        }
        type = 1 - type;
      }
      xx = x;
      yy = y;
      type = 1;
      sum -= down[xx][yy][type];
      down[xx][yy][type] = 0;
      sum += down[xx][yy][type];
      while (xx >= 0 && yy >= 0 && ((xx == x && yy == y) || !blocked[xx][yy])) {
        if (type == 0) {
          sum -= down[xx][yy][type];
          if (xx != x || yy != y)
            if (xx + 1 < n) down[xx][yy][type] = down[xx + 1][yy][1 - type] + 1;
          sum += down[xx][yy][type];
          yy--;
        } else {
          sum -= down[xx][yy][type];
          if (xx != x || yy != y)
            if (yy + 1 < m) down[xx][yy][type] = down[xx][yy + 1][1 - type] + 1;
          sum += down[xx][yy][type];
          xx--;
        }
        type = 1 - type;
      }
    }
    blocked[x][y] = !blocked[x][y];
    cout << sum - open << "\n";
  }
}
