#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> grid(n, vector<char>(m, '0'));
  bool poss = true;
  if (n % 2 == 1) {
    char st[2] = {'a', 'b'};
    int p = 0;
    for (int i = 0; i < m; i += 2, k--) {
      grid[n - 1][i] = st[p];
      grid[n - 1][i + 1] = st[p];
      p ^= 1;
    }
    n--;
  }
  if (k < 0) {
    cout << "NO" << endl;
    return;
  }
  char st[2] = {'c', 'd'};
  int p = 0;
  for (int i = 0, j = 0; k > 0; i++, k--, p ^= 1) {
    if (i == n) {
      i = 0;
      j += 2;
      p ^= 1;
    } else if (k == 1 && (n - i) % 2 == 0) {
      i = 0;
      j += 2;
      p ^= 1;
    }
    if (j >= (m - m % 2)) {
      cout << "NO" << endl;
      return;
    }
    grid[i][j] = st[p];
    grid[i][j + 1] = st[p];
  }
  char ch = 'e';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '0') {
        if (i + 1 >= n) {
          cout << "NO" << endl;
          return;
        }
        grid[i][j] = ch;
        grid[i + 1][j] = ch;
        ch = (ch == 'z') ? 'e' : ch + 1;
      }
    }
  }
  if (k != 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (auto str : grid) {
    for (auto ch : str) cout << ch;
    cout << endl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
