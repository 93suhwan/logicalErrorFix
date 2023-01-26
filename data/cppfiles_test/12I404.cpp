#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a;
  cin >> a;
  while (a--) {
    int b = 0, w = 0, x, y, z;
    cin >> x >> y >> z;
    for (int i = 1; i <= y; i++) {
      if (i % 2 == 1)
        b += x;
      else
        w += x;
    }
    while (z--) {
      b--;
      w--;
    }
    if (b % 2 == 1 || w % 2 == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
