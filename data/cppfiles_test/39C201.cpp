#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long H, W, h, w, x1, x2, y1, y2, ans = 0;
    double a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX;
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    if (w <= x1 || (W - x2) >= w || (h <= y1) || (H - y2) >= h)
      cout << 0 << "\n";
    else if (abs(w - x1) > abs(W - x2) && abs(h - y1) > abs(H - y2))
      cout << -1 << "\n";
    else {
      if (abs(w - x1) <= abs(W - x2)) a = abs(w - x1);
      if (abs(h - y1) <= abs(H - y2)) b = abs(h - y1);
      if (abs(x2 - (W - w)) <= abs(x1)) c = abs(x2 - (W - w));
      if (abs(y2 - (H - h)) <= abs(y1)) d = abs(y2 - (H - h));
      cout << fixed << setprecision(6);
      cout << min(min(a, b), min(c, d)) << "\n";
    }
  }
}
