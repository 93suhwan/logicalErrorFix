#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long W, H;
    cin >> W >> H;
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long w, h;
    cin >> w >> h;
    if (w + x2 - x1 > W && h + y2 - y1 > H) {
      cout << -1 << '\n';
      continue;
    }
    long long ans = inf;
    if (h + y2 - y1 <= H) ans = min(ans, h - y1);
    if (w + x2 - x1 <= W) ans = min(ans, w - x1);
    if (h + y2 - y1 <= H) ans = min(ans, y2 - (H - h));
    if (w + x2 - x1 <= W) ans = min(ans, x2 - (W - w));
    ans = max(ans, 0LL);
    cout << ans << '\n';
  }
}
