#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long ans = x;
    if (x % 2 == 0) {
      if (n % 4 == 1) {
        ans = ans - n;
      } else if (n % 4 == 2) {
        ans += 1;
      } else if (n % 4 == 3) {
        ans += 4 * ceil((n * 1.0) / 4);
      } else {
        ans = ans;
      }
    } else {
      if (n % 4 == 0) {
        ans = ans;
      } else if (n % 4 == 2) {
        ans -= 1;
      } else if (n % 4 == 3) {
        ans -= 4 * ceil((n * 1.0) / 4);
      } else {
        ans += n;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
