#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    if (a + b == c) {
      cout << a << " " << b << " " << d << "\n";
    } else {
      cout << a << " " << b << " " << c << "\n";
    }
  }
  return 0;
}
