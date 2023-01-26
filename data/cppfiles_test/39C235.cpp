#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int w, h;
  cin >> w >> h;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w1 = x2 - x1, h1 = y2 - y1, w2, h2;
  cin >> w2 >> h2;
  int ans = 1e9;
  if (w1 + w2 <= w) {
    ans = min(ans, max(0, w2 - x1));
    ans = min(ans, max(0, x2 - (w - w2)));
  }
  if (h1 + h2 <= h) {
    ans = min(ans, max(0, h2 - y1));
    ans = min(ans, max(0, y2 - (h - h2)));
  }
  cout << (ans == 1e9 ? -1 : ans);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve(), cout << '\n';
}
