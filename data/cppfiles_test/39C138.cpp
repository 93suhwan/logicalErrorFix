#include <bits/stdc++.h>
using namespace std;
const long long BIG_INF = 2e18;
const long long INF = 2e9;
const int MAXN = 1e5 + 7;
mt19937 engine;
double dist(long long x, long long y) {
  return double(sqrt(double(x) * double(x) + double(y) * double(y)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long W, H;
    cin >> W >> H;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long w2, h2;
    cin >> w2 >> h2;
    long long w1, h1;
    w1 = x2 - x1;
    h1 = y2 - y1;
    if (w1 + w2 > W && h1 + h2 > H) {
      cout << -1 << '\n';
      ;
      continue;
    }
    long long need_r, need_l, need_up, need_down;
    need_r = max(x2 - (W - w2), 0ll);
    need_l = max(w2 - x1, 0ll);
    need_up = max(y2 - (H - h2), 0ll);
    need_down = max(h2 - y1, 0ll);
    if (w1 + w2 <= W && h1 + h2 <= H) {
      cout << fixed << setprecision(9)
           << min({need_l, need_r, need_down, need_up}) << '\n';
      ;
    } else if (w1 + w2 <= W) {
      cout << fixed << setprecision(9) << min(need_l, need_r) << '\n';
      ;
    } else {
      cout << fixed << setprecision(9) << min(need_down, need_up) << '\n';
      ;
    }
  }
  return 0;
}
