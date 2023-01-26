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
        unsigned long long p = (y + i * x) / (i + 1);
        if (p % 2 == 0) {
          cout << p << endl;
          break;
        }
      }
    }
  }
}
