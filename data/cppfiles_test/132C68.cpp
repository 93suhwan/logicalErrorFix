#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d, e, f, g;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g;
    if (a + b < d)
      cout << a << " " << b << " " << d << endl;
    else
      cout << a << " " << b << " " << c << endl;
  }
}
