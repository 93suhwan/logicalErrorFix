#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i;
  for (i = 0; i < t; i++) {
    int x1, p1, x2, p2, a, b;
    cin >> x1 >> p1 >> x2 >> p2;
    a = x1 * (pow(10, p1));
    b = x2 * (pow(10, p2));
    if (a > b) {
      cout << ">" << endl;
    } else if (a < b) {
      cout << "<" << endl;
    } else {
      cout << "=" << endl;
    }
  }
}
