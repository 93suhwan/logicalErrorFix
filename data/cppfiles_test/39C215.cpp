#include <bits/stdc++.h>
using namespace std;
int main() {
  double k;
  int t, i, j, W, H, x1, y1, x2, y2, w, h, kw, kh, wt, ht;
  cin >> t;
  for (i = 0; i < t; ++i) {
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if (x2 - x1 + w > W) {
      wt = 0;
    } else {
      wt = 1;
    }
    if (y2 - y1 + h > H) {
      ht = 0;
    } else {
      ht = 1;
    }
    if (wt + ht == 0) {
      cout << -1 << endl;
    } else {
      if (W - x2 > x1) {
        kw = W - x2;
      } else {
        kw = x1;
      }
      if (H - y2 > y1) {
        kh = H - y2;
      } else {
        kh = y1;
      }
      if (w <= kw || h <= kh) {
        printf("%.9lf", 0);
        cout << endl;
      } else {
        if (wt + ht == 2) {
          if (w - kw < h - kh) {
            k = w - kw;
          } else {
            k = h - kh;
          }
        } else if (wt == 1) {
          k = w - kw;
        } else {
          k = h - kh;
        }
        printf("%.9lf", k);
        cout << endl;
      }
    }
  }
  return 0;
}
