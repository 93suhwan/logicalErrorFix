#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCase;
  cin >> testCase;
  for (int id = 0; id < testCase; id++) {
    int a, b, h, w;
    cin >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    int ans = 0x7fffffff;
    if (x2 - x1 + w > a) {
      if (y2 - y1 + h > b)
        ;
      else
        ans = min(ans, max(0, h - y1));
    } else {
      if (y2 - y1 + h > b)
        ans = min(ans, max(0, w - x1));
      else
        ans = min(ans, min(max(0, h - y1), max(0, w - x1)));
    }
    if (ans == 0x7fffffff)
      cout << -1 << "\n";
    else
      cout << (double)ans << "\n";
  }
  return 0;
}
