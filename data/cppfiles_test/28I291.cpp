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
    b = b % 2;
    if (c == 0 && b == 0) {
      ans = a % 2;
      cout << ans << "\n";
    } else if (c == 1 && b == 1) {
      ans = (a - 1) % 2;
      cout << ans << "\n";
    } else if (c == 1 && b == 0) {
      if (3 - a >= 0) {
        ans = 3 - 1;
        cout << ans << "\n";
        continue;
      } else {
        ans = (a - 3) % 2;
        cout << ans << "\n";
        continue;
      }
    } else if (c == 0 && b == 1) {
      if (a >= 2) {
        ans = (a - 2) % 2;
        cout << ans << "\n";
        continue;
      } else {
        ans = 2 - a;
        cout << ans << "\n";
        continue;
      }
    }
  }
  return 0;
}
