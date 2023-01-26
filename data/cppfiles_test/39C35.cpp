#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H, x1, x2, y1, y2, x, y;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if ((W < (x2 - x1) + (x)) && (H < (y2 - y1) + (y))) {
      cout << -1 << endl;
      continue;
    }
    long double ans = 0.000000;
    if ((x <= x1) || (x <= (W - x2)) || (y <= y1) || (y <= (H - y2))) {
      cout << fixed;
      cout << setprecision(6);
      cout << ans << endl;
    } else {
      long double hor1 = x - x1, hor2 = x2 - (W - x);
      long double ver1 = y - y1, ver2 = y2 - (H - y);
      if (x2 + hor1 > W) {
        hor1 = INT_MAX;
      }
      if (x1 - hor2 < 0) {
        hor2 = INT_MAX;
      }
      if (y2 + ver1 > H) {
        ver1 = INT_MAX;
      }
      if (y1 - ver2 < 0) {
        ver2 = INT_MAX;
      }
      long double a = min(hor1, min(hor2, min(ver1, ver2)));
      cout << fixed;
      cout << setprecision(6);
      cout << a << endl;
    }
  }
}
