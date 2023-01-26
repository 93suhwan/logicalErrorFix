#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  int w, h, x1, y1, x2, y2, a, b;
  cin >> t;
  while (t--) {
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> a >> b;
    int ans = 2e9;
    if (a + x2 - x1 <= w)
      ans = min(ans, min(max(x2 - (w - a), 0), max(a - x1, 0)));
    if (b + y2 - y1 <= h)
      ans = min(ans, min(max(y2 - (h - b), 0), max(b - y1, 0)));
    cout << (ans == 2e9 ? -1 : ans) << "\n";
  }
  return 0;
}
