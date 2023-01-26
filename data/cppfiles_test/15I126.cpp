#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int INF = INT_MAX;
const int N = 1e5 + 10;
const long double eps = 1e-6;
bool used[40][40], a[40][40];
void fnd(int i, int j, int k) {
  int x = i, y = j, c1 = 0, c2 = 0;
  while (a[x][y]) {
    ++c1;
    --x;
    --y;
  }
  x = i, y = j;
  while (a[x][y]) {
    ++c2;
    --x;
    ++y;
  }
  if (min(c1, c2) > k) {
    x = i, y = j;
    while (a[x][y]) {
      used[x][y] = true;
      --x;
      --y;
    }
    x = i, y = j;
    while (a[x][y]) {
      used[x][y] = true;
      --x;
      ++y;
    }
  }
  return;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = false;
  for (int i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      if (c == '.')
        a[i][j] = false, used[i][j] = true;
      else
        a[i][j] = true, used[i][j] = false;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j]) fnd(i, j, k);
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ok &= used[i][j];
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
