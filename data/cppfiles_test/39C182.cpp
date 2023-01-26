#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  cout << fixed << setprecision(9);
  while (t--) {
    int W, H, x1, x2, y1, y2;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int ans = INT_MAX;
    if (x2 - x1 + w <= W) {
      ans = min(ans, max(0, w - x1));
      ans = min(ans, max(0, x2 - (W - w)));
    }
    if (y2 - y1 + h <= H) {
      ans = min(ans, max(0, h - y1));
      ans = min(ans, max(0, y2 - (H - h)));
    }
    if (ans == INT_MAX)
      cout << -1 << endl;
    else
      cout << double(ans) << endl;
  }
  return 0;
}
