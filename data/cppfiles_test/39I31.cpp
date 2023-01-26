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
    if ((w + x2 - x1) > W && (h + y2 - y1) > H)
      cout << "-1" << endl;
    else {
      h1 = (double)w - x1;
      if (0 <= h1 && h1 <= W - x2) {
        if (ans < 0 || h1 < ans) {
          ans = h1;
        }
      }
      h2 = (double)w - (W - x2);
      if (0 <= h2 && h2 <= x1) {
        if (ans < 0 || h2 < ans) ans = h2;
      }
      h3 = (double)h - y1;
      if (0 <= h3 && h3 <= H - y2) {
        if (ans < 0 || h3 < ans) ans = h3;
      }
      h4 = (double)h - (H - y2);
      if (0 <= h4 && h4 <= y1) {
        if (ans < 0 || h4 < ans) ans = h4;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
