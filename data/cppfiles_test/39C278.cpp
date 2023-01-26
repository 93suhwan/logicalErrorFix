#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double W, H;
    scanf("%lf%lf", &W, &H);
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    double w, h;
    scanf("%lf%lf", &w, &h);
    if ((w + x2 - x1 > W && h + y2 - y1 > H) || (w == W && h + y2 - y1 > H) ||
        (w + x2 - x1 > W && h == H)) {
      printf("-1\n");
      continue;
    }
    double l = x1, r = W - x2, top = H - y2, bom = y1, ans = 0.0;
    if (max(l, r) >= w && max(top, bom) >= h)
      ans = 0.0;
    else if (w + x2 - x1 > W && h + y2 - y1 <= H) {
      if (max(bom, top) < h) ans = h - max(top, bom);
    } else if (w + x2 - x1 <= W && h + y2 - y1 > H) {
      if (max(l, r) < w) ans = w - max(l, r);
    } else {
      double x = 0.0, y = 0.0;
      if (max(l, r) < w) x = w - max(l, r);
      if (max(top, bom) < h) y = h - max(top, bom);
      ans = min(x, y);
    }
    printf("%.9f\n", ans);
  }
  return 0;
}
