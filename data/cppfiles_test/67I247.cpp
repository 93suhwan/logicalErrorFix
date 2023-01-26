#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, dist, d;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b >> c;
    dist = abs(a - b);
    d = (c + dist) % (2 * dist);
    if (d == a || d == b || c > 2 * dist || abs(a - c) != abs(b - d)) {
      d = -1;
    }
    cout << d << endl;
  }
  return 0;
}
