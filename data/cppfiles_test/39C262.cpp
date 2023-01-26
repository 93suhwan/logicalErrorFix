#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 10;
const long long MOD = 998244353;
const long long INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-12;
const long double PI = acos(-1);
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout << fixed << setprecision(12);
  long long t;
  cin >> t;
  while (t--) {
    long double W, H, w, h;
    long double x1, y1, x2, y2;
    cin >> W >> H;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    long double wt = x2 - x1;
    long double ht = y2 - y1;
    long double ans = LLINF;
    if (h + ht <= H) {
      ans = min(ans, h - y1);
      ans = min(ans, y2 - (H - h));
    }
    if (w + wt <= W) {
      ans = min(ans, w - x1);
      ans = min(ans, x2 - (W - w));
    }
    ans = max(ans, (long double)0);
    if (ans == LLINF)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
