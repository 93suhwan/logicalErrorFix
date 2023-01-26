#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    while (a != 0 && b != 0 && c != 0) {
      if (a / 2 <= m && a != 0) {
        m = m - a / 2;
        a = 0;
      } else if (a != 0 && a / 2 > m) {
        a--;
      }
      if (b / 2 <= m & b != 0) {
        m = m - b / 2;
        b = 0;
      } else if (b != 0 && b / 2 > m) {
        b--;
      }
      if (c / 2 <= m && c != 0) {
        m = m - c / 2;
        c = 0;
      } else if (c != 0 && c / 2 > m) {
        m--;
      }
    }
    if (m == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
