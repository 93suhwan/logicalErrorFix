#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int W, H, x1, x2, y1, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  long long int x = abs(x2 - x1), y = abs(y2 - y1);
  if (x + w > W and y + h > H)
    cout << -1 << "\n";
  else if (x1 >= w or W - x2 >= w or y1 >= h or H - y2 >= h)
    cout << fixed << setprecision(9) << 0.0 << "\n";
  else {
    long long int dx = 1e18, dy = 1e18;
    if (w + x <= W)
      dx = (abs(w - x1) > abs(w - (W - x2)) ? abs(w - (W - x2)) : abs(w - x1));
    if (h + y <= H)
      dy = (abs(h - y1) > abs(h - (H - y2)) ? abs(h - (H - y2)) : abs(h - y1));
    cout << fixed << setprecision(9) << (long double)(dx > dy ? dy : dx)
         << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int ttc;
  cin >> ttc;
  while (ttc--) solve();
  return 0;
}
