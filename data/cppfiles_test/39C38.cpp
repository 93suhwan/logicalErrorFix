#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 7;
signed main() {
  int T;
  cin >> T;
  while (T--) {
    int W, H, x1, y1, x2, y2, w, h, ans = inf;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if ((x2 - x1) + w > W && (y2 - y1) + h > H)
      ans = -1;
    else {
      if ((x2 - x1) + w <= W) {
        if (x1 >= w || W - x2 >= w)
          ans = 0;
        else
          ans = min(w - x1, x2 - (W - w));
      }
      if ((y2 - y1 + h <= H)) {
        if (y1 >= h || H - y2 >= h)
          ans = 0;
        else
          ans = min(ans, min(h - y1, y2 - (H - h)));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
