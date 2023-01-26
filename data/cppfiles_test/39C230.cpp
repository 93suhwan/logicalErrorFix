#include <bits/stdc++.h>
using namespace std;
int t;
long long W, H, X1, X2, Y1, Y2, w2, h2;
int main() {
  cin >> t;
  while (t--) {
    cin >> W >> H >> X1 >> Y1 >> X2 >> Y2 >> w2 >> h2;
    int w1 = X2 - X1, h1 = Y2 - Y1;
    int up = H - Y2, down = Y1, left = X1, right = W - X2;
    double ans = 0;
    if (w1 + w2 > W && h1 + h2 > H) {
      puts("-1");
      continue;
    } else if (w1 + w2 > W || h1 + h2 > H) {
      if (w1 + w2 > W) {
        if (max(up, down) < h2) ans = h2 - max(up, down);
      } else {
        if (max(left, right) < w2) ans = w2 - max(left, right);
      }
    } else {
      int dist1 = 0, dist2 = 0;
      if (max(up, down) < h2) dist1 = h2 - max(up, down);
      if (max(left, right) < w2) dist2 = w2 - max(left, right);
      ans = min(dist1, dist2);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}
