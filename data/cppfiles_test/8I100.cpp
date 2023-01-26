#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, b;
    cin >> n;
    if (n == 1)
      cout << 1 << " " << 0 << endl;
    else {
      int a = n / 3;
      int m = (n - a) % 2;
      if (m == 0)
        b = (n - a) / 2;
      else
        b = (n - a) / 2 + 1;
      int c = n - 2 * a;
      if (abs(a - b) <= abs(a - c))
        cout << a << " " << b << endl;
      else
        cout << c << " " << a << endl;
    }
  }
  return 0;
}
