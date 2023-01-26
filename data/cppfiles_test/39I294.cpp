#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int W, H;
  int x1, x2, y1, y2;
  int w, h;
  while (t--) {
    scanf("%d %d", &W, &H);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d", &w, &h);
    if ((y1 < h && y2 + (h - y1) > H) && ((x1 < w) && x2 + (w - x1) > W)) {
      cout << -1 << endl;
      continue;
    }
    int a = 0x3f3f3f3f;
    int b = 0x3f3f3f3f;
    if ((y1 <= h && y2 + (h - y1) <= H)) {
      a = (h - y1);
    }
    if (((x1 <= w) && x2 + (w - x1) <= W)) b = (w - x1);
    printf("%.9lf\n", (double)min(a, b));
  }
}
