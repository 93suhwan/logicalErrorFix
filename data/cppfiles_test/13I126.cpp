#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int nmax = 100011, mod = 1e9 + 7, inf = 2000010000, key = 37;
void solve() {
  int n, m, k, mas[110][110] = {0}, cur = 1;
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    if (!(k <= m / 2 * n && k % 2 == 0)) {
      cout << "NO\n";
      return;
    }
  } else {
    k -= m / 2;
    if (!(k >= 0 && k % 2 == 0)) {
      cout << "NO\n";
      return;
    }
    for (int i = 1; i < m; i += 2) {
      mas[1][i] = mas[1][i + 1] = cur;
      cur++;
    }
  }
  cout << "YES\n";
  int x, y;
  x = 1 + n % 2;
  y = 1;
  while (cur <= k) {
    if (x == n + 1) {
      y += 2;
      x = 1 + n % 2;
    }
    mas[x][y] = mas[x][y + 1] = cur;
    cur++;
    x++;
    mas[x][y] = mas[x][y + 1] = cur;
    cur++;
    x++;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (mas[j][i] == 0) {
        mas[j][i] = mas[j + 1][i] = cur;
        cur++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << char(mas[i][j] + 'a');
    cout << "\n";
  }
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
