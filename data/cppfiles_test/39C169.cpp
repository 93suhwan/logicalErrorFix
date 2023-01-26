#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, x1, y1, x2, y2, w, h;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int right = n - x2;
    int left = x1;
    int up = m - y2;
    int down = y1;
    int mn = 1e9;
    int w1 = x2 - x1;
    int h1 = y2 - y1;
    if (w1 + w <= n) {
      mn = min(mn, max(0, w - right));
      mn = min(mn, max(0, w - left));
    }
    if (h1 + h <= m) {
      mn = min(mn, max(0, h - up));
      mn = min(mn, max(0, h - down));
    }
    if (mn == 1e9) mn = -1;
    cout << mn << "\n";
  }
  return 0;
}
