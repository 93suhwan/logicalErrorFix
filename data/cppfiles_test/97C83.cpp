#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll const inf = 1e18;
ifstream fin("input.txt");
ofstream fout("output.txt");
signed main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 3));
  vector<vector<int>> b(n, vector<int>(m, 3));
  vector<vector<int>> l(n, vector<int>(m, 0));
  vector<vector<int>> r(n, vector<int>(m, 0));
  bool may = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      if (c == '.') a[i][j] = 0;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 3) {
        int x = a[i - 1][j] / 2 + a[i + 1][j] / 2 + a[i][j - 1] / 2 +
                a[i][j + 1] / 2;
        if (x % 2 == 1) may = false;
      }
    }
  if (!may) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i == 0 || j == 0 || j == m - 1) {
        l[i][j] = 0;
        r[i][j] = 0;
        a[i][j] = 1;
      } else {
        l[i][j] = l[i - 1][j];
        r[i][j] = r[i - 1][j];
        if (a[i - 1][j] == 3) {
          if (a[i - 1][j - 1] == 3) l[i][j]++;
          if (a[i - 1][j + 1] == 3) r[i][j]++;
        }
        if (a[i][j] == 0) a[i][j] = min(l[i][j], r[i][j]) % 2 + 1;
      }
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != 3)
        if ((i + a[i][j]) % 2 == 0)
          b[i][j] = 1;
        else
          b[i][j] = 4;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 3) {
        b[i][j] = 0;
        if (a[i - 1][j] != 3) b[i][j] += b[i - 1][j];
        if (a[i + 1][j] != 3) b[i][j] += b[i + 1][j];
        if (a[i][j - 1] != 3) b[i][j] += b[i][j - 1];
        if (a[i][j + 1] != 3) b[i][j] += b[i][j + 1];
      }
    }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
