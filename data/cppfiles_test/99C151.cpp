#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long xo, n;
    cin >> xo >> n;
    if (xo % 2 == 0) {
      if (n % 4 == 0) {
        cout << xo << '\n';
      } else if (n % 4 == 1) {
        cout << xo - n << '\n';
      } else if (n % 4 == 2) {
        cout << xo + 1 << '\n';
      } else if (n % 4 == 3) {
        cout << xo + n + 1 << '\n';
      }
    } else {
      if (n % 4 == 0) {
        cout << xo << '\n';
      } else if (n % 4 == 1) {
        cout << xo + 1 + (n - 1) << '\n';
      } else if (n % 4 == 2) {
        cout << xo - 1 << '\n';
      } else if (n % 4 == 3) {
        cout << -n - 1 + xo << '\n';
      }
    }
  }
}
