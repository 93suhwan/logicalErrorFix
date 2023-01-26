#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d;
  cin >> t;
  while (t > 0) {
    t--;
    int k = 0, k2 = 0;
    cin >> a >> b >> c >> d;
    k = log10(a);
    k2 = log10(c);
    if (k + b > k2 + d)
      cout << '>';
    else if (k + b < k2 + d)
      cout << '<';
    else {
      a *= pow(10, k2 - k);
      if (a > c)
        cout << '>';
      else if (a < c)
        cout << '<';
      else
        cout << '=';
    }
  }
}
