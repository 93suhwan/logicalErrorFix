#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    float W, H;
    scanf("%f%f", &W, &H);
    float x1, y1, x2, y2;
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    float w, h;
    scanf("%f%f", &w, &h);
    if ((w + x2 - x1 > W && h + y2 - y1 > H) || w > W || h > H) {
      printf("-1\n");
      continue;
    }
    float l = x1, r = W - x2, top = H - y2, bom = y1, x, y, ans = 1e8;
    if (l >= r) {
      if (top >= bom) {
        if (l < w)
          x = w - l;
        else
          x = 0;
        if (top >= h)
          y = 0;
        else
          y = h - top;
      } else {
        if (l < w)
          x = w - l;
        else
          x = 0;
        if (bom >= h)
          y = 0;
        else
          y = h - bom;
      }
    } else {
      if (top >= bom) {
        if (r < w)
          x = w - r;
        else
          x = 0;
        if (top >= h)
          y = 0;
        else
          y = h - top;
      } else {
        if (r < x)
          x = w - r;
        else
          x = 0;
        if (bom >= h)
          y = 0;
        else
          y = h - bom;
      }
    }
    if (w + x2 - x1 > W && h + y2 - y1 <= H) {
      ans = y;
    } else if (w + x2 - x1 <= W && h + y2 - y1 > H) {
      ans = x;
    } else
      ans = min(x, y);
    printf("%.9f\n", ans);
  }
  return 0;
}
