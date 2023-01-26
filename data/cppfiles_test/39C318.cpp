#include <bits/stdc++.h>
using namespace std;
void solve() {
  int W, H, x1, x2, y1, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  int ans = INT_MAX;
  if (x2 - x1 + w <= W) {
    ans = min(ans, max(0, w - x1));
    ans = min(ans, max(0, x2 - (W - w)));
  }
  if (y2 - y1 + h <= H) {
    ans = min(ans, max(0, h - y1));
    ans = min(ans, max(0, y2 - (H - h)));
  }
  if (ans == INT_MAX) {
    cout << -1;
    return;
  }
  cout << ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
