#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long double x1, x2;
    int num1 = 0, num2 = 0;
    long long p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    while (true) {
      if (x1 / 10 < 1) break;
      x1 /= 10;
      ++num1;
    }
    while (true) {
      if (x2 / 10 < 1) break;
      x2 /= 10;
      ++num2;
    }
    if (num1 + p1 > num2 + p2)
      cout << ">" << endl;
    else if (num1 + p1 < num2 + p2)
      cout << "<" << endl;
    else if (x1 > x2)
      cout << ">" << endl;
    else if (x1 < x2)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
  return 0;
}
