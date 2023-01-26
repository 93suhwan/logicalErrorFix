#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t = 0;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    long long a = 0, r = 0, c = 0, y = 0;
    long double n = 0, z = 0;
    cin >> n;
    y = sqrt(n);
    z = sqrt(n);
    if (y == z) {
      c = 1;
      r = y;
    } else {
      a = floor(sqrt(n)) + 1;
      if (n >= ((a * a) - a + 1)) {
        r = a;
        long long d = r * r;
        for (long long j = a; j > 0; --j) {
          if (n == d) {
            c = a - j + 1;
            break;
          }
          d--;
        }
      } else {
        c = a;
        long long e = pow(c - 1, 2) + 1;
        for (long long j = 0; j < c - 1; ++j) {
          if (n == e) {
            r = j + 1;
            break;
          }
          e++;
        }
      }
    }
    cout << r << " " << c << endl;
  }
  return 0;
}
