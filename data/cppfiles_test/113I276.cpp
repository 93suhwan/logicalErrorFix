#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int x, p, y, q;
  for (int i = 1; i <= t; ++i) {
    cin >> x >> p;
    cin >> y >> q;
    int n = pow(10, p) * x;
    int m = pow(10, q) * y;
    ;
    if (n > m) cout << ">" << endl;
    if (n == m) cout << "=" << endl;
    if (n < m) cout << "<" << endl;
  }
}
