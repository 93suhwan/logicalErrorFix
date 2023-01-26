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
    int ans = 0;
    if (y1 >= h || x1 >= w || (H - y2) >= h || (W - x2) >= w) {
      ans = 0;
    } else if (((long)y1 + H - y2) >= h && ((long)x1 + W - x2) >= w) {
      ans = min(h - max(y1, H - y2), w - max(x1, W - x2));
    } else if (((long)y1 + H - y2) >= h) {
      ans = h - max(y1, H - y2);
    } else if (((long)x1 + W - x2) >= w) {
      ans = w - max(x1, W - x2);
    } else
      ans = -1;
    cout << ans << endl;
  }
}
