#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, r1, c1, r2, c2;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    if (r2 >= r1 && c2 >= c1) {
      cout << min(r2 - r1, c2 - c1) << endl;
    } else if (r2 >= r1) {
      cout << min(2 * n - c1 - c2, r2 - r1) << endl;
    } else if (c2 >= c1) {
      cout << min(2 * n - r1 - r2, c2 - c1) << endl;
    } else {
      int mn1 = min(n - r1, m - c1);
      mn1 *= 2;
      if (n - r1 > m - c1) {
        if (r1 + mn1 <= n)
          r1 += mn1;
        else
          r1 = n - (mn1 - n + r1);
      } else {
        if (c1 + mn1 <= m)
          c1 += mn1;
        else
          c1 = m - (mn1 - m + c1);
      }
      int mn2 = min(r1 - r2, c1 - c2);
      cout << mn1 + mn2 << endl;
    }
  }
  return 0;
}
