#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long x, y;
    cin >> x >> y;
    if (x > y)
      cout << (x * y + y) << endl;
    else
      cout << (y - (y % x) / 2) << endl;
  }
  return 0;
}
