#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int W, H, x1, y1, x2, y2, w, h, ans = INT_MAX, a = 0;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if (x2 - x1 + w <= W) {
      ans = min(ans, max(a, w - x1));
      ans = min(ans, max(a, x2 - (W - w)));
    }
    if (y2 - y1 + h <= H) {
      ans = min(ans, max(a, h - y1));
      ans = min(ans, max(a, y2 - (H - h)));
    }
    if (ans == INT_MAX)
      cout << -1;
    else
      cout << fixed << setprecision(9) << (double)ans;
    cout << endl;
  }
}
