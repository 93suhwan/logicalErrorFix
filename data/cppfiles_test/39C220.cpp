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
    int ans = INT_MAX;
    int flag = 0;
    if (h + y2 - y1 <= H and w <= W) {
      h - y1 <= 0 ? ans = 0 : ans = min(ans, h - y1);
      h + y2 - H <= 0 ? ans = 0 : ans = min(ans, h + y2 - H);
      flag = 1;
    }
    if (w + x2 - x1 <= W and h <= H) {
      w - x1 <= 0 ? ans = 0 : ans = min(ans, w - x1);
      w + x2 - W <= 0 ? ans = 0 : ans = min(ans, w + x2 - W);
      flag = 1;
    }
    if (!flag) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
