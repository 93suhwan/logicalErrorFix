#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a;
  cin >> a;
  while (a--) {
    long long b, w, x, y, z;
    cin >> x >> y >> z;
    if (y == 1) {
      if (z == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
    if (x == 1) {
      if (z == y / 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
    if (y % 2 == 0) {
      b = y / 2;
      b *= x;
      b -= z;
      if (b % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
    if (y % 2 == 1) {
      b = y / 2;
      w = b + 1;
      b *= x;
      w *= x;
      b -= z;
      w -= z;
      if (b % 2 == 0 && w % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
  }
}
