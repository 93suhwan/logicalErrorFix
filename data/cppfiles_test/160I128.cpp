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
    else if (x > w) {
      if (y < z)
        cout << z - y << endl;
      else if (y >= z)
        cout << (m - y) * 2 + y - z << endl;
    } else {
      cout << w - x << endl;
    }
  }
  return 0;
}
