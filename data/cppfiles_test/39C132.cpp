#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long W, H;
    cin >> W;
    cin >> H;
    long long x1, y1, x2, y2;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    long long w, h;
    cin >> w;
    cin >> h;
    double h1, h2, h3, h4, ans = -1;
    if ((w + x2 - x1) > (W + 0.00000001) && (h + y2 - y1) > (H + 0.00000001))
      cout << "-1" << endl;
    else {
      h1 = max(0.0, (double)w - x1);
      if (h1 <= W - x2 + 0.00000001) {
        if (ans < -0.5 || h1 < ans) {
          ans = h1;
        }
      }
      h2 = max(0.0, (double)w - (W - x2));
      if (h2 <= x1 + 0.00000001) {
        if (ans < -0.5 || h2 < ans) ans = h2;
      }
      h3 = max(0.0, (double)h - y1);
      if (h3 <= H - y2 + 0.00000001) {
        if (ans < -0.5 || h3 < ans) ans = h3;
      }
      h4 = max(0.0, (double)h - (H - y2));
      if (h4 <= y1 + 0.00000001) {
        if (ans < -0.5 || h4 < ans) ans = h4;
      }
      cout.precision(10);
      if (ans < -0.5)
        cout << "-1" << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
