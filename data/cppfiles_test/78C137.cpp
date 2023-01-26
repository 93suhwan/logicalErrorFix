#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int l = 0, r = 1e9, m, res;
    while (l <= r) {
      m = (l + r) / 2;
      int x_l = m + 1;
      int x_r = 2 * m + 1;
      if (x_l < a) {
        x_r += a - x_l;
        x_l = a;
      }
      if (a <= x_l && x_r <= b) {
        res = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    cout << res << '\n';
  }
  return 0;
}
