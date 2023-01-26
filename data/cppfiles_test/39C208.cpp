#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  int w, h, x1, y1, x2, y2, a, b;
  cin >> t;
  while (t--) {
    cin >> w >> h;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a >> b;
    int delW = w - x2, delW2 = x1;
    int delH = h - y2, delH2 = y1;
    int ans = 2e9;
    if (delW >= delW2 && delH <= delH2) {
      if (w - a >= x2 || b <= y1)
        ans = 0;
      else {
        if (x2 - (w - a) <= x1) ans = min(ans, x2 - (w - a));
        if (b - y1 <= h - y2) ans = min(ans, b - y1);
      }
    } else if (delW < delW2 && delH <= delH2) {
      if (a <= x1 || b <= y1)
        ans = 0;
      else {
        if (a - x1 <= w - x2) ans = min(ans, a - x1);
        if (b - y1 <= h - y2) ans = min(ans, b - y1);
      }
    } else if (delW >= delW2 && delH > delH2) {
      if (h - b >= y2 || w - a >= x2)
        ans = 0;
      else {
        if (y2 - (h - b) <= y1) ans = min(ans, y2 - (h - b));
        if (x2 - (w - a) <= x1) ans = min(ans, x2 - (w - a));
      }
    } else if (delW < delW2 && delH > delH2) {
      if (h - b >= y2 || a <= x1)
        ans = 0;
      else {
        if (y2 - (h - b) <= y1) ans = min(ans, y2 - (h - b));
        if (a - x1 <= w - x2) ans = min(ans, a - x1);
      }
    }
    cout << (ans == 2e9 ? -1 : ans) << "\n";
  }
  return 0;
}
