#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, rx, ry, cx, cy;
    cin >> x >> y >> rx >> ry >> cx >> cy;
    if (rx > cx && ry > cy) {
      cout << min(rx - cx + 2 * (x - rx), ry - cy + 2 * (y - ry)) << endl;
    } else if (rx > cx && ry <= cy) {
      cout << min(rx - cx + 2 * (x - rx), cy - ry) << endl;
    } else if (rx <= cx && ry > cy) {
      cout << min(cx - rx, ry - cy + 2 * (y - ry)) << endl;
    } else if (rx <= cx && ry <= cy) {
      cout << min(cx - rx, cy - ry) << endl;
    }
  }
  return 0;
}
