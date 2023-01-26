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
        unsigned long long shang = (y + i * x);
        unsigned long long xia = i + 1;
        unsigned long long p = shang / xia;
        if (shang % xia == 0 && p < y) {
          cout << p << endl;
          break;
        }
      }
    }
  }
}
