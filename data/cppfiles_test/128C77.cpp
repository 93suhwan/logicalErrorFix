#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t t;
  cin >> t;
  for (int64_t h = 0; h < t; h++) {
    int64_t n;
    cin >> n;
    int64_t a, b, c;
    if (n % 2 == 0) {
      a = n - 3;
      b = 2;
      c = 1;
    } else {
      c = 1;
      if ((n / 2) % 2 == 0) {
        a = (n / 2) + 1;
        b = (n / 2) - 1;
      } else {
        a = (n / 2) + 2;
        b = (n / 2) - 2;
      }
    }
    cout << a << ' ' << b << ' ' << c << '\n';
  }
}
