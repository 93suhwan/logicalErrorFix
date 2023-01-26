#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, d;
    double x;
    cin >> k;
    x = sqrt(k);
    if (floor(x) == x)
      cout << x << " " << 1 << endl;
    else {
      x = floor(x);
      d = k - x * x;
      if (d <= x + 1)
        cout << d << " " << x + 1;
      else
        cout << x + 1 << " " << 2 * x + 2 - d;
      cout << endl;
    }
  }
  return 0;
}
