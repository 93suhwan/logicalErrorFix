#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int th = abs(y2 - y1), tw = abs(x1 - x2);
    if (tw + w > W && th + h > H)
      cout << -1 << endl;
    else {
      double ans[4];
      double a = 0, b = 0;
      if (h > y1) {
        a = h - y1;
        if (h + a > H) a = -1;
      }
      if (w > x1) {
        b = w - x1;
        if (w + b > W) b = -1;
      }
      if (a != -1 && b != -1)
        ans[0] = min(a, b);
      else if (a != -1)
        ans[0] = a;
      else if (b != -1)
        ans[0] = b;
      a = 0, b = 0;
      if (y1 + th > H - h) {
        a = y1 + th - (H - h);
        if (h + a > H) a = -1;
      }
      if (w > x1) {
        b = w - x1;
        if (w + b > W) b = -1;
      }
      if (a != -1 && b != -1)
        ans[1] = min(a, b);
      else if (a != -1)
        ans[1] = a;
      else if (b != -1)
        ans[1] = b;
      a = 0, b = 0;
      if (h > y1) {
        a = h - y1;
        if (h + a > H) a = -1;
      }
      if (x1 + tw > W - w) {
        b = x1 + tw - (W - w);
        if (w + b > W) b = -1;
      }
      if (a != -1 && b != -1)
        ans[2] = min(a, b);
      else if (a != -1)
        ans[2] = a;
      else if (b != -1)
        ans[2] = b;
      a = 0, b = 0;
      if (y1 + th > H - h) {
        a = y1 + th - (H - h);
        if (h + a > H) a = -1;
      }
      if (x1 + tw > W - w) {
        b = x1 + tw - (W - w);
        if (w + b > W) b = -1;
      }
      if (a != -1 && b != -1)
        ans[3] = min(a, b);
      else if (a != -1)
        ans[3] = a;
      else if (b != -1)
        ans[3] = b;
      double res;
      res = min(ans[0], min(ans[1], min(ans[2], ans[3])));
      printf("%.9lf\n", res);
    }
  }
  return 0;
}
