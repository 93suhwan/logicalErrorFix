#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, a, b, c, d, e, f, g;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> a >> b >> c >> d >> e >> f >> g;
    if (a + b + c == g) {
      cout << a << " " << b << " " << c << " " << endl;
    } else {
      cout << a << " " << b << " " << d << " " << endl;
    }
  }
}
