#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h, W, H, x1, x2, y1, y2, x = LONG_LONG_MAX,
                                              y = LONG_LONG_MAX;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    long long int k1 = W - x2;
    long long int k2 = H - y2;
    long long int p1 = x1;
    long long int p2 = y1;
    if (p1 + k1 < w && p2 + k2 < h) {
      cout << -1 << '\n';
      continue;
    }
    if (p1 + k1 >= w) {
      x = min(w - k1, w - p1);
      if (x < 0) {
        x = 0;
      }
    }
    if (p2 + k2 >= h) {
      y = min(h - k2, h - p2);
      if (y < 0) {
        y = 0;
      }
    }
    cout << min(x, y) << '\n';
  }
  return 0;
}
