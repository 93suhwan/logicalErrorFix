#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if ((a - 1) >= m) {
      a -= m;
      m = 0;
    } else {
      m -= (a - 1);
    }
    if ((b - 1) >= m) {
      b -= m;
      m = 0;
    } else {
      m -= (b - 1);
    }
    if ((c - 1) >= m) {
      c -= m;
      m = 0;
    } else {
      m -= (c - 1);
    }
    if (m > 0) {
      cout << "NO" << endl;
    } else {
      int rem = a + b + c;
      int maxp = (rem + 1) / 2;
      if (a > maxp || b > maxp || c > maxp) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
