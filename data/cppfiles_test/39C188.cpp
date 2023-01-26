#include <bits/stdc++.h>
using namespace std;
void solve() {
  int W, H;
  cin >> W >> H;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w1 = x2 - x1;
  int h1 = y2 - y1;
  int w, h;
  cin >> w >> h;
  if (w + w1 > W && h + h1 > H) {
    cout << "-1\n";
    return;
  }
  int wd1 = x1, wd2 = W - x2;
  int hg1 = y1, hg2 = H - y2;
  if (max(wd1, wd2) >= w || max(hg1, hg2) >= h) {
    cout << "0.000000000\n";
    return;
  }
  int a = INT_MAX, b = INT_MAX;
  if (w1 + w <= W) {
    a = min(w - wd1, w - wd2);
  }
  if (h1 + h <= H) {
    b = min(h - hg1, h - hg2);
  }
  int ans = min(a, b);
  cout << setprecision(9) << fixed << (float)ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
