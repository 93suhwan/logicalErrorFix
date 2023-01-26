#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long x, p, y, q;
  for (long long i = 1; i <= t; ++i) {
    cin >> x >> p;
    cin >> y >> q;
    if (p > q) {
      long long d = p - q;
      if (d > 6) cout << ">" << endl;
      if (d == 6 && x == 1 && y == 1e6) cout << "=" << endl;
      if (d == 6 && (x != 1 || y != 1e6)) cout << ">" << endl;
      if (d < 6) {
        long long n = pow(10, d) * x;
        if (n > y) cout << ">" << endl;
        if (n == y) cout << "=" << endl;
        if (n < y) cout << "<" << endl;
      }
    }
    if (p == q) {
      if (x > y) cout << ">" << endl;
      if (x == y) cout << "=" << endl;
      if (x < y) cout << "<" << endl;
    }
    if (p < q) {
      long long d = q - p;
      if (d > 6) cout << "<" << endl;
      if (d == 6 && y == 1 && x == 1e6) cout << "=" << endl;
      if (d == 6 && (y != 1 || x != 1e6)) cout << "<" << endl;
      if (d < 6) {
        long long n = pow(10, d) * y;
        if (x > n) cout << ">" << endl;
        if (x == n) cout << "=" << endl;
        if (x < n) cout << "<" << endl;
      }
    }
  }
}
