#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  unsigned long long x, y;
  while (t--) {
    cin >> x >> y;
    if (x == y) {
      cout << x << endl;
    } else if (x > y) {
      unsigned long long ans = x + y;
      cout << ans << endl;
    } else {
      unsigned long long ans = y - (y % x) / 2;
      cout << ans << endl;
    }
  }
}
