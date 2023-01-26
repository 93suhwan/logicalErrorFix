#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, x, y, z;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    z = abs(x - y);
    if (z & 1) {
      cout << -1 << endl;
    } else {
      if (x == 0) {
        cout << 0 << endl;
      } else {
        cout << (z == 0 ? 1 : 2) << endl;
      }
    }
  }
  return 0;
}
