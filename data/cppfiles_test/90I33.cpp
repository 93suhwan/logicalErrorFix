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
      for (int i = 1; i <= 1e6; i++) {
        unsigned long long shang = (i * x + y);
        unsigned long long xia = 2;
        unsigned long long p = shang / xia;
        if (shang % xia == 0 && p < y && p > x && p % x != 0) {
          cout << p << endl;
          break;
        }
      }
    }
  }
}
