#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h, x1, y1, x2, y2, ww, hh, a = -1;
  cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> ww >> hh;
  if (hh + y2 - y1 <= h) {
    if (hh <= y1) {
      a = 0;
    } else {
      if (a == -1 || a > hh - y1) {
        a = hh - y1;
      }
    }
    if (h - hh >= y2) {
      a = 0;
    } else {
      if (a == -1 || a > y2 - (h - hh)) {
        a = y2 - (h - hh);
      }
    }
  }
  if (ww + x2 - x1 <= w) {
    if (ww <= x1) {
      a = 0;
    } else {
      if (a == -1 || a > ww - x1) {
        a = ww - x1;
      }
    }
    if (w - ww >= x2) {
      a = 0;
    } else {
      if (a == -1 || a > x2 - (w - ww)) {
        a = x2 - (w - ww);
      }
    }
  }
  cout << a << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
