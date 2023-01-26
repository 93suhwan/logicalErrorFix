#include <bits/stdc++.h>
using namespace std;
float min(float a, float b) {
  if (a <= b)
    return a;
  else
    return b;
}
float min_dis(float W, float H, float x1, float y1, float x2, float y2, float w,
              float h) {
  float dis, dis1, dis2;
  if ((x2 - x1 + w) > W && (y2 - y1 + h) > H) {
    return -1;
  } else {
    if ((x2 - x1 + w) <= W && (y2 - y1 + h) <= H) {
      dis = 0;
    } else if ((y2 - y1 + h) > H) {
      if (w <= x1 || w <= (W - x2)) {
        dis = 0;
      } else {
        dis = min(w - x1, w - (W - x2));
      }
    } else {
      if (h <= y1 || h <= (H - y2)) {
        dis = 0;
      } else {
        dis = min(h - y1, h - (H - y2));
      }
    }
  }
  return dis;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    float W, H;
    cin >> W >> H;
    float x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    float w, h;
    cin >> w >> h;
    float dis = min_dis(W, H, x1, y1, x2, y2, w, h);
    cout << setprecision(6) << dis << endl;
  }
}
