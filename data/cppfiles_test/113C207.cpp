#include <bits/stdc++.h>
using namespace std;
int power(int a) {
  int i = 0;
  while (a > 0) {
    i++;
    a /= 10;
  }
  return i;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int k1 = power(x1);
    int k2 = power(x2);
    if (k1 + p1 > k2 + p2)
      cout << ">\n";
    else if (k1 + p1 < k2 + p2)
      cout << "<\n";
    else {
      if (k1 > k2) {
        for (int i = 0; i < k1 - k2; i++) {
          x2 = x2 * 10;
        }
      } else if (k2 > k1) {
        for (int i = 0; i < k2 - k1; i++) {
          x1 = x1 * 10;
        }
      }
      if (x1 > x2)
        cout << ">\n";
      else if (x2 > x1)
        cout << "<\n";
      else
        cout << "=\n";
    }
  }
  return 0;
}
