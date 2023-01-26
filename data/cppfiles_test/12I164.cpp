#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a;
  cin >> a;
  while (a--) {
    int b = 0, w = 0, x, y, z;
    cin >> x >> y >> z;
    if (y % 2 == 0) {
      b = y / 2;
      b *= x;
      b -= z;
      if (b % 2 == 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
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
    }
  }
}
