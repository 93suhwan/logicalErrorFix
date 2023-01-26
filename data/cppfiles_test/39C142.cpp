#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000005;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int main() {
  int t, w, h, x1, x2, y1, y2, n, m, ans;
  t = read();
  while (t--) {
    cin >> w >> h;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n >> m;
    ans = 1000000005;
    if (x2 - x1 + n <= w) {
      ans = min(ans, max(0, n - x1));
      ans = min(ans, max(0, x2 - w + n));
    }
    if (y2 - y1 + m <= h) {
      ans = min(ans, max(0, m - y1));
      ans = min(ans, max(0, y2 - h + m));
    }
    if (ans == INF)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
