#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long h, w, x1, x2, y1, y2, a, b, W, H;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  a = x2 - x1, b = y2 - y1;
  long long x, y, ans = 1e18, tx, ty;
  bool got = 0;
  tx = w, ty = h;
  x = max(0ll, tx - x1);
  y = max(0ll, ty - y1);
  if (tx + a <= W) {
    got = 1;
    ans = min(ans, (x));
  }
  if (ty + b <= H) {
    got = 1;
    ans = min(ans, (y));
  }
  tx = W - w, ty = h;
  x = max(0ll, x2 - tx);
  y = max(0ll, ty - y1);
  if (tx - a >= 0) {
    got = 1;
    ans = min(ans, (x));
  }
  if (ty + b <= H) {
    got = 1;
    ans = min(ans, (y));
  }
  tx = W - w, ty = H - h;
  y = max(0ll, y2 - ty);
  if (ty - b >= 0) {
    got = 1;
    ans = min(ans, (y));
  }
  if (got)
    cout << ans << ".000000000\n";
  else
    cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
