#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, q1;
    cin >> x1 >> q1;
    int x2, q2;
    cin >> x2 >> q2;
    int p1, p2;
    p1 = (int)log10(x1);
    p2 = (int)log10(x2);
    if (p1 >= p2) {
      q2 -= p1 - p2;
      x2 *= pow(10, p1 - p2);
    } else {
      q1 -= p2 - p1;
      x1 *= pow(10, p2 - p1);
    }
    if (x1 > x2) {
      if (q1 >= q2)
        cout << '>';
      else
        cout << '<';
    } else if (x1 == x2) {
      if (q1 > q2)
        cout << '>';
      else if (q2 > q1)
        cout << '<';
      else
        cout << '=';
    } else if (x2 > x1) {
      if (q1 > q2)
        cout << '>';
      else
        cout << '<';
    }
    cout << '\n';
  }
}
