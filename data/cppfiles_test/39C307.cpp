#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int ans = 1000000000;
    if (w + (x2 - x1) <= W) {
      ans = min(ans, max(0, w - x1));
      ans = min(ans, max(0, x2 - W + w));
    }
    if (h + (y2 - y1) <= H) {
      ans = min(ans, max(0, h - y1));
      ans = min(ans, max(0, y2 - H + h));
    }
    double p = ans;
    if (ans == 1000000000)
      cout << "-1\n";
    else
      printf("%.6f\n", p);
  }
}
