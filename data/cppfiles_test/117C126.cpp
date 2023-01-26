#include <bits/stdc++.h>
using namespace std;
const long long mxlli = 1e18;
const int mod = 1e9 + 7;
const int msize = 2e5 + 2;
vector<vector<char>> a;
void f(int x, int y, int n, int m) {
  if (a[x][y] != '.') return;
  int p = 0;
  int xx = x, yy = y;
  if (x < n - 1 && a[x + 1][y] == '.') p++, xx = x + 1;
  if (y < m - 1 && a[x][y + 1] == '.') p++, yy = y + 1;
  if (x > 0 && a[x - 1][y] == '.') p++, xx = x - 1;
  if (y > 0 && a[x][y - 1] == '.') p++, yy = y - 1;
  if (p <= 1) {
    a[x][y] = '+';
    f(xx, yy, n, m);
  }
}
int solv(int T) {
  int n, m, i, j;
  cin >> n >> m;
  a.clear();
  a.assign(n, {});
  int x = -1, y = -1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      a[i].push_back(ch);
      if (a[i][j] == 'L') x = i, y = j;
    }
  }
  if (x < n - 1) f(x + 1, y, n, m);
  if (y < m - 1) f(x, y + 1, n, m);
  if (x > 0) f(x - 1, y, n, m);
  if (y > 0) f(x, y - 1, n, m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  cin >> testcases;
  for (int T = 1; T <= testcases; T++) {
    solv(T);
  }
}
