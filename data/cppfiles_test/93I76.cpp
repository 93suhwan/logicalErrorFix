#include <bits/stdc++.h>
using namespace std;
long long x[300005];
int main() {
  long long t;
  cin >> t;
  long long xr;
  for (long long i = 0; i < 300005; i++) {
    if (i == 0) {
      xr = 0;
    } else {
      xr = xr ^ i;
    }
    x[i] = xr;
  }
  while (t--) {
    long long a, b;
    cin >> a >> b;
    xr = x[a - 1];
    if (xr == b) {
      cout << a << endl;
    } else if (xr == 0) {
      if (a == b) {
        cout << a + 2 << endl;
      } else
        cout << a + 1 << endl;
    } else {
      if ((xr ^ b) == (xr - b)) {
        long long d = xr - b;
        if (d == a) {
          cout << a + 2 << endl;
        } else
          cout << a + 1 << endl;
      } else {
        if ((xr & b) == xr) {
          if ((xr + b) == a) {
            cout << a + 2 << endl;
          } else
            cout << a + 1 << endl;
        } else {
          if ((xr ^ b) == a) {
            cout << a + 2 << endl;
          } else
            cout << a + 1 << endl;
        }
      }
    }
  }
}
