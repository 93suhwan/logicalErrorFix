#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    long long th = abs(y2 - y1), tw = abs(x1 - x2);
    if (tw + w > W && th + h > H)
      cout << -1 << endl;
    else {
      double ans[4];
      double a = 0, b = 0;
      bool f = 0, g = 0;
      if (h > y1) {
        a = (double)h - (double)y1;
        if ((double)h + a > (double)H) f = 1;
      }
      if (w > x1) {
        b = (double)w - (double)x1;
        if ((double)w + b > (double)W) g = 1;
      }
      if (f == 0 && g == 0)
        ans[0] = min(a, b);
      else if (g == 1)
        ans[0] = a;
      else if (f == 1)
        ans[0] = b;
      a = 0, b = 0;
      f = 0, g = 0;
      if (y1 + th > H - h) {
        a = (double)y1 + (double)th - ((double)H - (double)h);
        if ((double)h + a > (double)H) f = 1;
      }
      if (w > x1) {
        b = (double)w - (double)x1;
        if ((double)w + b > (double)W) g = -1;
      }
      if (f == 0 && g == 0)
        ans[1] = min(a, b);
      else if (g)
        ans[1] = a;
      else if (f)
        ans[1] = b;
      a = 0, b = 0, f = 0, g = 0;
      if (h > y1) {
        a = (double)h - (double)y1;
        if ((double)h + a > (double)H) f = 1;
      }
      if (x1 + tw > W - w) {
        b = (double)x1 + (double)tw - ((double)W - (double)w);
        if ((double)w + b > (double)W) g = 1;
      }
      if (f == 0 && g == 0)
        ans[2] = min(a, b);
      else if (g)
        ans[2] = a;
      else if (f)
        ans[2] = b;
      a = 0, b = 0, f = 0, g = 0;
      if (y1 + th > H - h) {
        a = (double)y1 + (double)th - ((double)H - (double)h);
        if ((double)h + a > (double)H) f = 1;
      }
      if (x1 + tw > W - w) {
        b = (double)x1 + (double)tw - ((double)W - (double)w);
        if ((double)w + b > (double)W) g = 1;
      }
      if (f == 0 && g == 0)
        ans[3] = min(a, b);
      else if (g)
        ans[3] = a;
      else if (f)
        ans[3] = b;
      double res;
      res = min(ans[0], min(ans[1], min(ans[2], ans[3])));
      printf("%.9lf\n", res);
    }
  }
  return 0;
}
