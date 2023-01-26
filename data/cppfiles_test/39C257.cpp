#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 7;
const int N = 1e5 + 5;
double pi = acos(-1);
int t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int w, h, W, H, x1, y2, x2, y1;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int x = x2 - x1;
    int y = y2 - y1;
    int res = 1e9;
    if (h + y <= H) {
      if (H >= h + y2) {
        res = 0;
      } else {
        res = min(res, y2 - H + h);
      }
      if (h <= y1) {
        res = 0;
      } else {
        res = min(res, h - y1);
      }
    }
    if (x + w <= W) {
      if (x1 >= w) {
        res = 0;
      } else {
        res = min(res, w - x1);
      }
      if (W - x2 >= w) {
        res = 0;
      } else {
        res = min(res, w + x2 - W);
      }
    }
    if (res == 1e9)
      cout << -1 << '\n';
    else
      cout << fixed << setprecision(9) << double(res) << '\n';
  }
  return 0;
}
