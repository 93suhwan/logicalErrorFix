#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 20, M = 2e5 + 1;
long long arr[M];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long w, h, x, x1, x2, y, y1, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> x >> y;
    double ans = M;
    cout << fixed << setprecision(9);
    if (y >= y1 && (y - y1 <= h - y2))
      ans = min(max((y - y1), 0LL), (long long)ans);
    if (x >= x1 && (x - x1 <= w - x2))
      ans = min(max((0LL), (x - x1)), (long long)ans);
    if (ans == M)
      cout << "-1\n";
    else
      cout << ans << '\n';
  }
  return 0;
}
