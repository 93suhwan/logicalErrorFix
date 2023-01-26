#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5, mod = 1e9 + 7;
int main(void) {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    }
    function<bool(int, int)> check = [&](int x, int y) {
      int sa = 0, sb = 0;
      for (int i = 0; i < n; i++) {
        if (a[i][x] && a[i][y]) {
          if (sa < sb)
            ++sa;
          else
            ++sb;
        } else if (a[i][x]) {
          ++sa;
        } else if (a[i][y]) {
          ++sb;
        } else {
          return false;
        }
      }
      if (sa == sb && (sa == n / 2))
        return true;
      else
        return false;
    };
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 5; j++) {
        if (check(i, j)) ok = 1;
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
