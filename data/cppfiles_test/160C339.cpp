#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y, w, z;
    cin >> n >> m >> x >> y >> w >> z;
    if (x == w || y == z)
      cout << 0 << endl;
    else {
      int r = 1, r1 = 1, r2 = 1;
      while (true) {
        if (x == w || y == z) break;
        if (x == n || x == 0) r1 *= -1;
        if (y == m || y == 0) r2 *= -1;
        x += r1;
        y += r2;
        r++;
      }
      cout << r - 1 << endl;
    }
  }
  return 0;
}
