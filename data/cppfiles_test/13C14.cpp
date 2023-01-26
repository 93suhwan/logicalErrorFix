#include <bits/stdc++.h>
using namespace std;
auto fast_io = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
long long int pow_mod(long long int a, long long int e, long long int mod) {
  long long int res = 1;
  while (e) {
    if (e & 1) res = res * a % mod;
    e >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long int inv_mod(long long int b, long long int m) {
  long long int a = m, x = 0, y = 1, r, q;
  while (b) {
    r = a % b;
    q = a / b;
    a = b;
    b = r;
    r = x;
    x = y;
    y = r - q * y;
  }
  x += m;
  return x % m;
}
bool place_dominos(int n, int m, int k, vector<vector<int> > &grid, int r,
                   int c) {
  int p = n * m / 2;
  if (k > p || (k & 1)) {
    return false;
  }
  for (int i = r; i < n + r && k; i += 2) {
    for (int j = c, ch = 0; j < m + c && k; j += 2, ch ^= 1) {
      grid[i][j] = grid[i][j + 1] = ch;
      grid[i + 1][j] = grid[i + 1][j + 1] = (ch ^ 1);
      k -= 2;
    }
  }
  for (int j = c, par = 0; j < m + c; j++, par ^= 1) {
    for (int i = r, ch = par; i < n + r; i += 2, ch ^= 1) {
      if (grid[i][j] == 'v' - 'a') {
        grid[i][j] = grid[i + 1][j] = ch + 'c' - 'a';
      }
    }
  }
  return true;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int> > grid(n, vector<int>(m, 'v' - 'a'));
  bool ok = false;
  if (n & 1) {
    assert(m % 2 == 0);
    if (k >= m / 2) {
      k -= m / 2;
      for (int i = 0, ch = 0; i < m; i += 2, ch ^= 1) {
        grid[0][i] = grid[0][i + 1] = ch + 'y' - 'a';
      }
      ok = place_dominos(n - 1, m, k, grid, 1, 0);
    }
  } else {
    if (m & 1) {
      for (int i = 0, ch = 0; i < n; i += 2, ch ^= 1) {
        grid[i][0] = grid[i + 1][0] = ch + 'y' - 'a';
      }
    }
    ok = place_dominos(n, m - (m & 1), k, grid, 0, (m & 1));
  }
  cout << (ok ? "YES" : "NO") << endl;
  if (ok) {
    for (auto x : grid) {
      for (auto y : x) cout << char(y + 'a');
      cout << endl;
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
