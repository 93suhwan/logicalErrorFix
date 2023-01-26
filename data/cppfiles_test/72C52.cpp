#include <bits/stdc++.h>
using namespace std;
const long long N = 1000004;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1000000000;
long long n, m, k, z, t, ans, x[2], y[2], pat, va, na, vd, nd;
int qq(int x, int y) {
  int q;
  cout << "? " << x << " " << y << endl;
  cin >> q;
  return q;
}
int main() {
  nd = qq(1, 1);
  na = qq(inf, 1);
  vd = qq(1, inf);
  va = qq(inf, inf);
  x[0] = 1 + qq(1, ((1 + nd) + (1e9 - vd)) / 2);
  y[0] = 1 + qq(((1 + nd) + (1e9 - na)) / 2, 1);
  x[1] = 1e9 - qq(1e9, ((1 + na) + (1e9 - va)) / 2);
  y[1] = 1e9 - qq(((1 + vd) + (1e9 - va)) / 2, 1e9);
  cout << '!' << " " << x[0] << " " << y[0] << " " << x[1] << " " << y[1]
       << endl;
  return 0;
}
