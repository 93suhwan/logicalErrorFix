#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int ans = 999999999;
    if (x2 - x1 + w <= W) {
      ans = min(ans, max(w - x1, 0));
      ans = min(ans, max(x2 - (W - w), 0));
    }
    if (y2 - y1 + h <= H) {
      ans = min(ans, max(h - y1, 0));
      ans = min(ans, max(y2 - (H - h), 0));
    }
    if (ans == 999999999) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
