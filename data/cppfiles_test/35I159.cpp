#include <bits/stdc++.h>
using namespace std;
void fileio() {}
void solve() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << "\n";
  } else {
    int z = 1;
    while (z < m + 1) {
      z *= 2;
    }
    if (z == m) {
      cout << z << "\n";
      return;
    }
    int x = n, mx = 0, ok = 0;
    for (auto i = m - 1; i >= 0; i--) {
      while (m & (1 << i) && !(n & (1 << i))) {
        n ^= (1 << i);
        if (n > m) {
          cout << n - x << "\n";
          return;
        }
        i++;
        ok = 1;
      }
      if (ok) break;
    }
    if (n > m) {
      cout << n - x << "\n";
      return;
    }
    for (auto i = m - 1; i >= 0; i--) {
      if (m & (1 << i) && !(n & (1 << i))) {
        n ^= (1 << (i + 1));
        break;
      }
    }
    if (n <= m) n ^= 1;
    cout << n - x;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  fileio();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
