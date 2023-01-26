#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
void solve() {
  int H, W, i, j, k;
  int x1, y1, x2, y2;
  scanf("%d %d", &W, &H);
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  int h1 = y2 - y1, w1 = x2 - x1, h2, w2, ans = 1e9;
  scanf("%d %d", &w2, &h2);
  if (h1 + h2 > H && w1 + w2 > W) {
    printf("-1\n");
    return;
  } else if (h1 + h2 > H) {
    if (w2 <= x1 || x2 <= W - w2) ans = 0;
    if (x1 < w2) ans = min(ans, w2 - x1);
    if (x2 > W - w2) ans = min(ans, x2 - (W - w2));
  } else if (w1 + w2 > W) {
    if (h2 <= y1 || y2 <= H - h2) ans = 0;
    if (y1 < h2) ans = min(ans, h2 - y1);
    if (y2 > H - h2 && ans) ans = min(ans, y2 - (H - h2));
  } else {
    if (w2 <= x1 || x2 <= W - w2) ans = 0;
    if (h2 <= y1 || y2 <= H - h2) ans = 0;
    if (x1 < w2) ans = min(ans, w2 - x1);
    if (x2 > W - w2) ans = min(ans, x2 - (W - w2));
    if (y1 < h2) ans = min(ans, h2 - y1);
    if (y2 > H - h2 && ans) ans = min(ans, y2 - (H - h2));
  }
  printf("%.8lf\n", (double)ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
