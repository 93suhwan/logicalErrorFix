#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, res;
    cin >> x >> y;
    if (x <= y) {
      if (y % x == 0)
        res = x;
      else
        res = y - x + 1;
    } else
      res = x + y;
    cout << res << endl;
  }
  return 0;
}
