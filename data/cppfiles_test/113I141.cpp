#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long x, p, y, q;
  for (long long i = 1; i <= t; ++i) {
    cin >> x >> p;
    cin >> y >> q;
    long long n = pow(10, p) * x;
    long long m = pow(10, q) * y;
    ;
    if (n > m) cout << ">" << endl;
    if (n == m) cout << "=" << endl;
    if (n < m) cout << "<" << endl;
  }
}
