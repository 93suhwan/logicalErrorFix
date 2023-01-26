#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w, h, x1, y1, x2, y2, w1, h1;
  cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> w1 >> h1;
  int ans = 1e9;
  bool flag = false;
  if ((x2 - x1) + w1 <= w) {
    flag = true;
    int need = max(0, w1 - x1);
    int need2 = max(0, x2 - (w - w1));
    ans = min({ans, need, need2});
  }
  if ((y2 - y1) + h1 <= h) {
    flag = true;
    int need = max(0, h1 - y1);
    int need2 = max(0, y2 - (h - h1));
    ans = min({ans, need, need2});
  }
  if (flag) {
    printf("%.9f", (double)ans);
    cout << endl;
  } else {
    cout << "-1" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
