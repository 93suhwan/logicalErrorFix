#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int T;
double x, xx, y, yy;
double W, H, w, h;
int main() {
  cin >> T;
  while (T--) {
    cin >> W >> H;
    cin >> x >> y >> xx >> yy;
    cin >> w >> h;
    if (w + (xx - x) > W && h + (yy - y) > H) {
      puts("-1");
      continue;
    }
    if (x >= W || y >= h || (W - xx) >= w || (H - yy) >= h) {
      puts("0");
      continue;
    }
    double dx = max(x, W - xx), dy = max(y, H - yy);
    double d1 = 1e18, d2 = 1e18;
    if (w > dx && w + xx - x <= W) d1 = w - dx;
    if (h > dy && h + yy - y <= H) d2 = h - dy;
    printf("%.10lf\n", min(d1, d2));
  }
  return 0;
}
