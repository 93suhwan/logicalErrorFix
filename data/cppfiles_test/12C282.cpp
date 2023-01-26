#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long inf = 1e18;
const char nl = '\n';
void solve_it() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m, '0'));
    int two = 0, hori = 0, verti = 0;
    for (int i = 0; i < (n); ++i) {
      for (int j = 0; j < (m); ++j) {
        if (grid[i][j] == '0') {
          if (j + 1 < m && i + 1 < n) {
            ++two;
            grid[i][j + 1] = '#';
            grid[i + 1][j] = '#';
            grid[i + 1][j + 1] = '#';
          } else if (i + 1 < n) {
            ++verti;
            grid[i][j] = '#';
            grid[i + 1][j] = '#';
          } else if (j + 1 < m) {
            ++hori;
            grid[i][j] = '#';
            grid[i][j + 1] = '#';
          }
        }
      }
    }
    int v = ((n * m) / 2) - k;
    if (hori >= k) {
      k = 0;
      hori -= k;
      if (v == verti + (2 * two) && hori == 0) {
        cout << "YES" << nl;
        continue;
      }
    } else {
      k -= hori;
      hori = 0;
    }
    if (k % 2 != 0) {
      cout << "NO" << nl;
      continue;
    }
    int cnthori = k / 2;
    if (two >= cnthori) {
      two -= cnthori;
      cnthori = 0;
      if (v == (verti + 2 * two)) {
        cout << "YES" << nl;
        continue;
      } else
        cout << "NO" << nl;
    } else {
      cout << "NO" << nl;
      continue;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve_it();
  return 0;
}
