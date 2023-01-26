#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> x(q), y(q);
  for (int i = (0); i < (q); i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<vector<long long>> u(n, vector<long long>(m, 1)),
      l(n, vector<long long>(m, 1));
  long long ans = 0, t = 0;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (m); j++) {
      if (i > 0) u[i][j] = l[i - 1][j] + 1;
      if (j > 0) l[i][j] = u[i][j - 1] + 1;
      ans += u[i][j] + l[i][j];
      t++;
    }
  }
  for (int i = (0); i < (q); i++) {
    if (u[x[i]][y[i]] > 0) {
      ans -= u[x[i]][y[i]] + l[x[i]][y[i]];
      t--;
      u[x[i]][y[i]] = 0;
      l[x[i]][y[i]] = 0;
    } else {
      t++;
      u[x[i]][y[i]] = 1;
      l[x[i]][y[i]] = 1;
      if (x[i] > 0) u[x[i]][y[i]] = l[x[i] - 1][y[i]] + 1;
      if (y[i] > 0) l[x[i]][y[i]] = u[x[i]][y[i] - 1] + 1;
      ans += u[x[i]][y[i]] + l[x[i]][y[i]];
    }
    for (int j = (x[i]); j < (n); j++) {
      for (int k = (y[i] + j - x[i] - 1); k < (y[i] + j - x[i] + 2); k++) {
        if (j == x[i]) {
          if (k < y[i] + j - x[i] + 1) continue;
        }
        if (k >= m) continue;
        if (u[j][k] == 0) continue;
        ans -= u[j][k] + l[j][k];
        u[j][k] = 1;
        l[j][k] = 1;
        if (j > 0) u[j][k] = l[j - 1][k] + 1;
        if (k > 0) l[j][k] = u[j][k - 1] + 1;
        ans += u[j][k] + l[j][k];
      }
    }
    cout << ans - t << endl;
  }
}
