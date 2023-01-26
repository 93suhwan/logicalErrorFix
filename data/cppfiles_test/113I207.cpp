#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int x, p, y, q;
  for (int i = 1; i <= t; ++i) {
    cin >> x >> p;
    cin >> y >> q;
    int n, m;
    int temp1 = pow(10, p) * x;
    int temp2 = pow(10, q) * y;
    n = max(x, temp1);
    m = max(y, temp2);
    if (n > m) cout << ">" << endl;
    if (n == m) cout << "=" << endl;
    if (n < m) cout << "<" << endl;
  }
}
