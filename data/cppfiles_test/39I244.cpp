#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long W, H;
  long long x1, x2, y1, y2;
  long long w, h;
  while (t--) {
    scanf("%lld %lld", &W, &H);
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld", &w, &h);
    if ((y1 < h && y2 + (h - y1) > H) && ((x1 < w) && x2 + (w - x1) > W)) {
      cout << -1 << endl;
      continue;
    }
    long long a = 0x3f3f3f3f3f;
    long long b = 0x3f3f3f3f3f;
    if (y1 >= h || x1 >= w) {
      cout << 0 << endl;
    } else {
      if ((y1 < h && y2 + (h - y1) <= H)) a = (h - y1);
      if (((x1 < w) && x2 + (w - x1) <= W)) b = (w - x1);
      printf("%lld\n", min(a, b));
    }
  }
}
