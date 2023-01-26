#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int ans = 0;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    c = c % 2;
    if (c == 0) {
      b = b % 2;
      if (b == 1) {
        ans = abs(a - 2) % 2;
        cout << ans << "\n";
      } else {
        ans = a % 2;
        cout << ans << "\n";
      }
    } else {
      if (a != 0 && b != 0) {
        a--;
        b--;
        b = b % 2;
        if (b == 1) {
          ans = abs(a - 2) % 2;
          cout << ans << "\n";
        } else {
          ans = a % 2;
          cout << ans << "\n";
        }
      }
    }
  }
  return 0;
}
