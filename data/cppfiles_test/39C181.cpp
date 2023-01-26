#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int W, H, x1, y1, x2, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  if (x2 - x1 + w > W && y2 - y1 + h > H)
    cout << "-1\n";
  else {
    if (x1 > w || W - x2 > w || y1 > h || H - y2 > h)
      cout << "0.0000000\n";
    else {
      long double a, b;
      if (x2 - x1 + w <= W) a = min(w - x1, w - (W - x2));
      if (y2 - y1 + h <= H) b = min(h - y1, h - (H - y2));
      if (x2 - x1 + w <= W && y2 - y1 + h > H)
        printf("%0.9Lf\n", a);
      else if (x2 - x1 + w > W && y2 - y1 + h <= H)
        printf("%0.9Lf\n", b);
      else if (x2 - x1 + w > W && y2 - y1 + h > H)
        cout << "-1"
             << "\n";
      else {
        printf("%0.9Lf\n", min(a, b));
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
