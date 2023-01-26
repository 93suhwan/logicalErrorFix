#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    long long x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    if (p1 - p2 >= 8)
      cout << ">\n";
    else if (p2 - p1 >= 8)
      cout << "<\n";
    else if (p2 > p1) {
      p2 -= p1;
      x2 *= (long long)pow(10, p2);
      if (x1 > x2)
        cout << ">\n";
      else if (x1 < x2)
        cout << "<\n";
      else
        cout << "=\n";
    } else {
      p1 -= p2;
      x1 *= (long long)pow(10, p1);
      if (x1 > x2)
        cout << ">\n";
      else if (x1 < x2)
        cout << "<\n";
      else
        cout << "=\n";
    }
  }
}
