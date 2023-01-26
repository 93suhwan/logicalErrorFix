#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    if (x > y)
      cout << x + y << '\n';
    else if (x == y)
      cout << x << '\n';
    else {
      long long int k = (x + y) / 2;
      if (y < 2 * x) {
        cout << k << '\n';
      } else if (!(y % x)) {
        cout << x << '\n';
      } else {
        cout << ((y / x) * x + y) / 2 << '\n';
      }
    }
  }
  return 0;
}
