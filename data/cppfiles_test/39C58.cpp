#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, w, h, w1, h1, x1, x2, y1, y2, a, b;
  cin >> t;
  while (t--) {
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> w1 >> h1;
    if (x2 - x1 + w1 > w && y2 - y1 + h1 > h) {
      cout << "-1" << '\n';
      continue;
    }
    if (x2 - x1 + w1 > w) {
      b = max(y1, h - y2);
      cout << fixed << setprecision(7) << h1 - min(h1, b) << '\n';
    } else if (y2 - y1 + h1 > h) {
      a = max(x1, w - x2);
      cout << fixed << setprecision(7) << w1 - min(w1, a) << '\n';
    } else {
      a = max(x1, w - x2);
      b = max(y1, h - y2);
      a = min(w1 - min(w1, a), h1 - min(h1, b));
      cout << fixed << setprecision(7) << a << '\n';
    }
  }
  return 0;
}
