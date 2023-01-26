#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, n, i, x, mx, mn, f, j, s, r, y, c, m,
      k = 0, W, H, x1, y1, w, h, w1, h1, l, u, d, sw, sh, X, Y, X1, X2, R;
  cin >> t;
  while (t--) {
    cin >> W >> H;
    cin >> x >> y >> x1 >> y1;
    cin >> w >> h;
    w1 = abs(x - x1);
    h1 = abs(y - y1);
    sw = W - w1;
    sh = H - h1;
    if (sw < w && sh < h)
      cout << -1 << endl;
    else {
      r = W - x1;
      l = x;
      u = H - y1;
      d = y;
      if (max(r, l) >= w || max(u, d) >= h)
        printf("%0.7lf\n", k);
      else {
        X = max(r, l);
        Y = max(u, d);
        X = w - X;
        Y = h - Y;
        if (X > min(r, l))
          R = Y;
        else if (Y > min(u, d))
          R = X;
        else
          R = min(X, Y);
        printf("%0.7lf\n", R);
      }
    }
  }
}
