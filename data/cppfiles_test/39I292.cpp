#include <bits/stdc++.h>
using namespace std;
float min_dis(float W, float H, float x1, float y1, float x2, float y2, float w,
              float h) {
  float dis;
  if ((x2 - x1 + w) > W && (y2 - y1 + h) > H) {
    return -1;
  } else {
    if ((x2 - x1 + w) > W) {
      float h1, h2;
      h1 = (h - y1);
      h2 = h - (H - y2);
      if (h1 <= h2) {
        dis = h1;
      } else {
        dis = h2;
      }
    } else if ((y2 - y1 + h) > H) {
      float w1, w2;
      w1 = (w - x1);
      w2 = w - (W - x2);
      if (w1 <= w2) {
        dis = w1;
      } else {
        dis = w2;
      }
    } else {
      dis = 0.0;
    }
  }
  if (dis < 0) {
    dis = 0.0;
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
