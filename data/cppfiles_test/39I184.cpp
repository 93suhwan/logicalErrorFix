#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int width = x2 - x1;
    int heigth = y2 - y1;
    int w, h;
    cin >> w >> h;
    int a, b, c, d;
    a = INT32_MAX;
    b = a, c = a, d = a;
    if ((width + w) > W && (heigth + h) > H) {
      cout << "-1\n";
      continue;
    }
    cout << fixed << setprecision(9);
    if (x1 >= w || y1 >= h || (W - x2) >= w || (H - y2) >= h) {
      cout << "0.000000000\n";
    } else {
      if ((heigth + h) <= H) {
        a = h - y1;
        b = h - H + y2;
      }
      if ((width + w) <= W) {
        c = w - x1;
        d = w - H + x2;
      }
      cout << (double)min(min(a, b), min(c, d)) << endl;
    }
  }
  return 0;
}
