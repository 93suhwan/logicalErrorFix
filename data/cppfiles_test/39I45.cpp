#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    int boo = 0;
    long w, h;
    cin >> w >> h;
    long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long w2, h2;
    cin >> w2 >> h2;
    long mindist = 0;
    long maxmarginwidth, maxmarginheight;
    long w1 = x2 - x1;
    long h1 = y2 - y1;
    if (w1 + w2 > w & h1 + h2 > h) {
      mindist = -1;
      boo = 1;
    } else {
      if (w - x2 > x1)
        maxmarginwidth = w - x2;
      else
        maxmarginwidth = x1;
      if (h - y2 > y1)
        maxmarginheight = h - y2;
      else
        maxmarginheight = y1;
    }
    if (maxmarginwidth >= w2 && maxmarginheight >= h2 && boo == 0) {
      mindist = 0;
    }
    if (std::min(w2 - maxmarginwidth, h2 - maxmarginheight) ==
            w2 - maxmarginwidth &&
        boo == 0) {
      if (w1 + w2 > w) {
        mindist = h2 - maxmarginheight;
      } else {
        mindist = w2 - maxmarginwidth;
      }
    } else {
      if (boo == 0) {
        if (h1 + h2 > h) {
          mindist = w2 - maxmarginwidth;
        } else {
          mindist = h2 - maxmarginheight;
        }
      }
    }
    cout << fixed << setprecision(9) << mindist << endl;
  }
}
