#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  int ans = 1;
  while (x > 0) {
    ans *= 10;
    x--;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    int d = 0;
    int x = x1;
    while (x1 > 9) {
      d++;
      x1 /= 10;
      p1++;
    }
    double a = x / (1.0 * f(d));
    d = 0;
    int y = x2;
    while (x2 > 9) {
      d++;
      x2 /= 10;
      p2++;
    }
    double b = y / (1.0 * f(d));
    if (p1 < p2) {
      cout << "<" << endl;
    } else if (p1 > p2) {
      cout << ">" << endl;
    } else {
      if (a > b) {
        cout << ">" << endl;
      } else if (a < b) {
        cout << "<" << endl;
      } else {
        cout << "=" << endl;
      }
    }
  }
  return 0;
}
