#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d, z;
  cin >> t;
  z = t;
  char xs[t + 1];
  while (t > 0) {
    t--;
    int k = 0, k2 = 0;
    cin >> a >> b >> c >> d;
    k = log10(a);
    k2 = log10(c);
    if (k + b > k2 + d)
      xs[t] = '>';
    else if (k + b < k2 + d)
      xs[t] = '<';
    else {
      if (a < c)
        a *= pow(10, k2 - k);
      else
        c *= pow(10, k - k2);
      if (a > c)
        xs[t] = '>';
      else if (a < c)
        xs[t] = '<';
      else
        xs[t] = '=';
    }
  }
  t = z;
  while (t > 0) {
    t--;
    cout << xs[t] << endl;
  }
}
