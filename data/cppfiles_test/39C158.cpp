#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int W, H, x1, y1, x2, y2, w2, h2;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
    int w1 = x2 - x1, h1 = y2 - y1;
    int mi = 1e9;
    if (W >= (w1 + w2)) {
      mi = min(mi, x2 - (W - w2));
      mi = min(mi, w2 - x1);
    }
    if (H >= (h1 + h2)) {
      mi = min(mi, y2 - (H - h2));
      mi = min(mi, h2 - y1);
    }
    mi = max(mi, 0);
    if (mi == 1e9)
      cout << "-1\n";
    else
      cout << fixed << setprecision(9) << double(mi) << "\n";
  }
  return 0;
}
