#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h;
  cin >> w >> h;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w1, h1;
  cin >> w1 >> h1;
  int ans = INT_MAX;
  int total_w = x2 - x1 + w1;
  if (total_w <= w) {
    ans = min(ans, max(0, w1 - x1));
    ans = min(ans, max(0, x2 - (w - w1)));
  }
  int total_h = y2 - y1 + h1;
  if (total_h <= h) {
    ans = min(ans, max(0, h1 - y1));
    ans = min(ans, max(0, y2 - (h - h1)));
  }
  cout << fixed << setprecision(9);
  if (ans == INT_MAX)
    cout << -1 << endl;
  else
    cout << double(ans) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
