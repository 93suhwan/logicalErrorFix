#include <bits/stdc++.h>
using namespace std;
inline double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
inline int mabs(int x) { return x < 0 ? -x : x; }
inline int madoka(int x) { return x < 0 ? 0 : x; }
int t;
int w, h, ww, hh, wid, hei;
int lxl1, lxl2, lyl1, lyl2;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &w, &h);
    scanf("%d%d%d%d", &lxl1, &lyl1, &lxl2, &lyl2);
    scanf("%d%d", &ww, &hh);
    wid = mabs(lxl1 - lxl2);
    hei = mabs(lyl1 - lyl2);
    double ans = 998244353.114514;
    if (ww + wid > w && hh + hei > h) {
      printf("-1\n");
      continue;
    } else {
      if (ww + wid <= w) {
        ans = min(ans, (double)min(madoka(ww - lxl1), madoka(lxl2 - w + ww)));
      }
      if (hh + hei <= h) {
        ans = min(ans, (double)min(madoka(hh - lyl1), madoka(lyl2 - h + hh)));
      }
    }
    if (ans >= 998244353)
      printf("-1\n");
    else
      printf("%.9lf\n", ans);
  }
}
