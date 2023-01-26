#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int W, H, x1, y1, x2, y2;
  int w, h;
  int w1, h1;
  while (t--) {
    scanf("%d %d", &W, &H);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d", &w, &h);
    int aaa = x2 - x1;
    int bbb = y2 - y1;
    int minni = 0x3f3f3f3f;
    if (w1 > W || h1 > H || w > W || h > H || (aaa + w > W && bbb + h > H)) {
      printf("-1\n");
    } else {
      if ((x1 >= w) || (y1 >= h) || (H - y2 >= h) || (W - x2 >= w))
        puts("0");
      else {
        if (w + aaa <= W) {
          minni = min(minni, abs(W - w - x2));
          minni = min(minni, abs(w - x1));
        }
        if (h + bbb <= H) {
          minni = min(minni, abs(h - y1));
          minni = min(minni, abs(H - h - y2));
        }
        printf("%d\n", minni);
      }
    }
  }
  return 0;
}
