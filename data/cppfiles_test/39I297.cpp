#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  long long W, H, x1, y1, x2, y2;
  long long w, h;
  long long w1, h1;
  while (t--) {
    scanf("%lld %lld", &W, &H);
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld", &w, &h);
    long long minni = 0x3f3f3f3f;
    if (w1 > W || h1 > H || w > W || h > H ||
        (x2 - x1 + w > W && y2 - y1 + h > H)) {
      printf("-1\n");
    } else {
      if ((x1 >= w) || (y1 >= h) || (H - y2 >= h) || (W - x2 >= w))
        puts("0");
      else {
        if (w + w1 <= W) {
          minni = min(minni, abs(W - w - x2));
          minni = min(minni, abs(w - x1));
        }
        if (h + h1 <= H) {
          minni = min(minni, abs(H - h - y2));
          minni = min(minni, abs(h - y1));
        }
        printf("%lld\n", minni);
      }
    }
  }
  return 0;
}
