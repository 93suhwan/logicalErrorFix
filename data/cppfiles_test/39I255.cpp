#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}
int min_dis(int W, int H, int x1, int y1, int x2, float y2, int w, int h) {
  int dis;
  if (h > H || w > W) {
    return -1;
  } else {
    if ((x2 - x1 + w) > W && (y2 - y1 + h) > H) {
      return -1;
    } else {
      if (w <= x1 || w <= (W - x2)) {
        dis = 0;
      } else if (h <= y1 || h <= (H - y2)) {
        dis = 0;
      } else {
        int dis1 = 100000001;
        int dis2 = 100000001;
        if (w + (x2 - x1) <= W) {
          dis1 = min(w - x1, w - (W - x2));
        }
        if (h + (y2 - y1) <= H) {
          dis2 = min(h - (H - y2), h - y1);
        }
        dis = min(dis1, dis2);
      }
    }
  }
  if (dis < 0) {
    dis = 0;
  }
  return dis;
}
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
    int dis = min_dis(W, H, x1, y1, x2, y2, w, h);
    cout << dis << endl;
  }
}
