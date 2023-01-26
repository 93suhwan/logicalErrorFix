#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long W, H, a, b, c, d, w, h, ds = 1000000007;
    cin >> W >> H >> a >> b >> c >> d >> w >> h;
    if ((w + c - a) > W && (h + d - b) > H)
      cout << -1;
    else {
      if ((w + c - a) <= W) {
        ds = min(ds, max((long long)0, w - a));
        ds = min(ds, max((long long)0, w - W + c));
      } else {
        ds = min(ds, max((long long)0, h - b));
        ds = min(ds, max((long long)0, h - H + d));
      }
      cout << ds;
    }
    cout << '\n';
  }
}
