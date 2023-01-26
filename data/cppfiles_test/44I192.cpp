#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, x, y, z;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (abs(x - y) == 0) {
      cout << 0 << endl;
    } else if (abs(x - y) == 1) {
      cout << -1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
  return 0;
}
