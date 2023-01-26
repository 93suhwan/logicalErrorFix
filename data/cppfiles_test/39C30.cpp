#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
void solve() {
  double w, h;
  cin >> w >> h;
  double a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  double w1, h1;
  cin >> w1 >> h1;
  double ans = 0x3f3f3f3f;
  double ans1;
  if (a2 - a1 + w1 <= w + eps) {
    ans1 = w1 - a1;
    if (ans1 <= 0) ans1 = 0;
    ans = min(ans, ans1);
    ans1 = w1 - (w - a2);
    if (ans1 <= 0) ans1 = 0;
    ans = min(ans, ans1);
  }
  if (b2 - b1 + h1 <= h + eps) {
    ans1 = h1 - b1;
    if (ans1 <= 0) ans1 = 0;
    ans = min(ans, ans1);
    ans1 = h1 - (h - b2);
    if (ans1 <= 0) ans1 = 0;
    ans = min(ans, ans1);
  }
  if (ans > 0x3f3f3f3f / 2) {
    cout << -1 << "\n";
    return;
  }
  printf("%.9lf\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
