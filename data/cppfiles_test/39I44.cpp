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
    int w, h;
    cin >> w >> h;
    if (y1 >= h || x1 >= w || (H - y2) >= h || (W - x2) >= w) {
      cout << 0 << endl;
    } else if ((y1 + H - y2) >= h) {
      cout << min(y1, H - y2) << endl;
    } else if ((x1 + W - x2) >= w) {
      cout << min(x1, W - x2) << endl;
    } else
      cout << -1 << endl;
  }
}
