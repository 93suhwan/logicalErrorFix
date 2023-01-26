#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int off = (n % m);
    if (off == 0) {
      int sz = n / m;
      while (k--) {
        for (int i = 1, x = 1; i <= n; ++i, ++x) {
          if (x == 1) {
            cout << sz << ' ';
          }
          cout << i << ' ';
          if (x == sz) {
            cout << '\n';
            x = 0;
          }
        }
      }
      continue;
    } else {
      int ctb = off;
      int big = (n + m - 1) / m;
      off = big * off;
      int start, ini = -off + 1;
      while (k--) {
        ini += off;
        if (ini > n) {
          ini = ini - n;
        }
        start = ini;
        if (start > n) {
          start = start - n;
        }
        for (int i = 0; i < ctb; ++i) {
          cout << big << ' ';
          for (int j = 0; j < big; ++j) {
            cout << start++ << ' ';
            if (start > n) {
              start = 1;
            }
          }
          cout << '\n';
        }
        for (int i = 0; i < m - ctb; ++i) {
          cout << big - 1 << ' ';
          for (int j = 0; j < big - 1; ++j) {
            cout << start++ << ' ';
            if (start > n) {
              start = 1;
            }
          }
          cout << '\n';
        }
      }
    }
  }
  return 0;
}
