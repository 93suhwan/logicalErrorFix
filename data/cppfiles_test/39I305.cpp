#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long W, H;
  cin >> W >> H;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long w, h;
  cin >> w >> h;
  long long ans = LLONG_MAX;
  long long width = abs(x2 - x1), height = abs(y2 - y1);
  if (width + w <= W) {
    long long left = min(x1, x2);
    long long right = W - max(x1, x2);
    if (left >= w || right >= w) {
      ans = min(ans, 0LL);
    }
    ans = min({ans, w - left, w - right});
  }
  if (height + h <= H) {
    long long up = H - max(y1, y2);
    long long down = min(y1, y2);
    if (up >= h || down >= h) {
      ans = min(ans, 0LL);
    }
    ans = min({ans, h - up, h - down});
  }
  if (ans == LLONG_MAX) ans = -1;
  double A = 1.0 * ans;
  cout << fixed << setprecision(10) << A << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
}
