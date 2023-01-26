#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x1, p1, x2, p2, d1 = 0, d2 = 0;
    cin >> x1 >> p1 >> x2 >> p2;
    long long int t1 = x1;
    long long int t2 = x2;
    while (t1 != 0) {
      d1++;
      t1 = t1 / 10;
    }
    long long int k1 = d1;
    d1 = d1 + p1;
    while (t2 != 0) {
      d2++;
      t2 = t2 / 10;
    }
    long long int k2 = d2;
    d2 = d2 + p2;
    if (d1 > d2)
      cout << ">\n";
    else if (d1 < d2)
      cout << "<\n";
    else {
      if (k1 < k2) {
        while (k1 != k2) {
          x1 = x1 * 10;
          k1++;
        }
      } else {
        while (k1 != k2) {
          x2 = x2 * 10;
          k2++;
        }
      }
      if (x1 == x2)
        cout << "=\n";
      else if (x1 > x2)
        cout << ">\n";
      else
        cout << "<\n";
    }
  }
  return 0;
}
