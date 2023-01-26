#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    if ((x + y == z) || (z + y == x) || (x + z == y) ||
        (x == y && z % 2 == 0) || (y == z && x % 2 == 0) ||
        (x == z && y % 2 == 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
