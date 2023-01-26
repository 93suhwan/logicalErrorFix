#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, res;
    cin >> x >> y;
    if (x <= y)
      res = y - (y % x) / 2;
    else
      res = x + y;
    cout << res << endl;
  }
  return 0;
}
