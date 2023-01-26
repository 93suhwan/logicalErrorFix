#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    int a = max(x, y);
    int b = min(x, y);
    int n = 2 * (a - b);
    if (a - 2 * b < 0) {
      cout << "-1\n";
    } else {
      if (z > n) {
        cout << "-1\n";
      } else {
        if (a - b + z > n) {
          cout << z - a + b << "\n";
        } else {
          cout << z + a - b << "\n";
        }
      }
    }
  }
  return 0;
}
