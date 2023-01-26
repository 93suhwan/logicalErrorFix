#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void solve() {
  int W, H;
  cin >> W >> H;
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  int w, h;
  cin >> w >> h;
  int ans = inf;
  if (w + (xb - xa) <= W) {
    ans = min(ans, max(0, w - xa));
    ans = min(ans, max(0, xb - (W - w)));
  }
  if (h + (yb - ya) <= H) {
    ans = min(ans, max(0, h - ya));
    ans = min(ans, max(0, yb - (H - h)));
  }
  cout << (ans == inf ? -1 : ans) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
