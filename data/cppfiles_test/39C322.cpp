#include <bits/stdc++.h>
using namespace std;
const int mxN = 50005, mod = 1e9 + 7;
int n, x1, x2, yi, y2, w, h, W, H, sx, sy, sol;
int main() {
  cout << setprecision(10) << fixed;
  int t;
  cin >> t;
  while (t--) {
    scanf("%d %d", &W, &H);
    scanf("%d %d %d %d", &x1, &yi, &x2, &y2);
    scanf("%d %d", &w, &h);
    sol = 1e9;
    if (W - (x2 - x1) < w && H - (y2 - yi) < h) {
      cout << -1 << '\n';
      continue;
    }
    if (x1 >= w || W - x2 >= w) {
      cout << 0 << '\n';
      continue;
    }
    if (yi >= h || H - y2 >= h) {
      cout << 0 << '\n';
      continue;
    }
    if (x1 > W - x2) {
      if (x1 + W - x2 >= w) {
        sol = w - x1;
      }
    } else {
      if (x1 + W - x2 >= w) sol = w - W + x2;
    }
    if (yi > H - y2) {
      if (yi + H - y2 >= h) sol = min(h - yi, sol);
    } else {
      if (yi + H - y2 >= h) sol = min(h - H + y2, sol);
    }
    cout << (float)sol << '\n';
  }
  return 0;
}
