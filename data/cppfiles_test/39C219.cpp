#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int w1 = x2 - x1;
    int h1 = y2 - y1;
    if (w1 + w > W && h1 + h > H) {
      cout << -1 << '\n';
      continue;
    }
    int currMin = INT_MAX;
    if (w1 + w <= W) {
      int try1 = max(0, w - x1);
      currMin = min(try1, currMin);
      int try2 = max(0, x2 + w - W);
      currMin = min(try2, currMin);
    }
    if (h1 + h <= H) {
      int try1 = max(0, h - y1);
      currMin = min(try1, currMin);
      int try2 = max(0, y2 + h - H);
      currMin = min(try2, currMin);
    }
    cout << currMin << '\n';
  }
}
