#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
const int mod = 1000000007;
int T, n, m, k;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    int sx, sy, dx, dy;
    cin >> n >> m >> sx >> sy >> dx >> dy;
    int ans;
    if (dx >= sx && dy >= sy) {
      ans = min(dx - sx, dy - sy);
    } else if (dx >= sx && dy < sy) {
      ans = min(dx - sx, 2 * m - dy - sy);
    } else if (dx < sx && dy < sy) {
      ans = min(2 * n - dx - sx, 2 * m - dy - sy);
    } else {
      ans = min(2 * n - dx - sx, dy - sy);
    }
    cout << ans << '\n';
  }
  return 0;
}
