#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w1 = x2 - x1;
    int h1 = y2 - y1;
    int w2, h2;
    cin >> w2 >> h2;
    int dist = -1;
    bool possible = false;
    if ((W >= (w1 + w2)) && (H >= h2)) {
      possible = true;
      if ((x1 >= w2) || (x2 + w2 <= W)) {
        cout << 0 << endl;
        continue;
      }
      int v1 = w2 - x1;
      int v2 = w2 - W + x2;
      dist = v1 < v2 ? v1 : v2;
    }
    if ((H >= (h1 + h2)) && (W >= w2)) {
      possible = true;
      if ((y1 >= h2) || ((y2 + h2) <= H)) {
        cout << 0 << endl;
        continue;
      }
      int v1 = h2 - y1;
      int v2 = h2 - H + y2;
      if (dist == -1)
        dist = v1 < v2 ? v1 : v2;
      else if (dist > v1)
        dist = v1;
      if (dist > v2) dist = v2;
    }
    if (!possible) {
      cout << -1 << endl;
      continue;
    }
    cout << dist << endl;
  }
  return 0;
}
