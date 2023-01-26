#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long w1 = x2 - x1;
    long long h1 = y2 - y1;
    long long w2, h2;
    cin >> w2 >> h2;
    if (w1 + w2 > w && h1 + h2 > h) {
      cout << -1;
      cout << "\n";
      continue;
    }
    long long ans = 0;
    if (w1 + w2 <= w && h1 + h2 <= h) {
      ans = min(min(w2 - x1, w2 - (w - x2)), min(h2 - y1, h2 - (h - y2)));
    } else {
      if (w1 + w2 <= w) {
        ans = min(w2 - x1, w2 - (w - x2));
      } else if (h1 + h2 <= h) {
        ans = min(h2 - y1, h2 - (h - y2));
      }
    }
    cout << fixed << setprecision(9) << (double)max(0ll, ans);
    cout << "\n";
  }
  return 0;
}
