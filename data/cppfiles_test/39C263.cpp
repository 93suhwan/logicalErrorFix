#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e2 + 2;
void solve() {
  int W, H;
  cin >> W >> H;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int w, h;
  cin >> w >> h;
  if (w + abs(x1 - x2) > W && h + abs(y1 - y2) > H) {
    cout << -1 << "\n";
    return;
  }
  int ans = 1e9;
  if (w + abs(x1 - x2) <= W) {
    int r = max(x1, W - x2);
    ans = min(ans, max(0, w - r));
  }
  if (h + abs(y1 - y2) <= H) {
    int c = max(y1, H - y2);
    ans = min(ans, max(0, h - c));
  }
  cout << fixed << setprecision(10) << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    solve();
  }
  return 0;
}
