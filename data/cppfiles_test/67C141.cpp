#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, dist, d;
  cin >> t;
  int* r = new int[t];
  for (int i = 0; i < t; ++i) {
    cin >> a >> b >> c;
    dist = abs(a - b);
    d = (c + dist) % (2 * dist);
    if (d == 0) {
      d += 2 * dist;
    }
    if (d == a || d == b && ((a - c) % (2 * dist) != (b - d) % (2 * dist)) ||
        (c > 2 * dist || a > 2 * dist || b > 2 * dist)) {
      d = -1;
    }
    r[i] = d;
  }
  for (int i = 0; i < t; ++i) {
    cout << r[i] << endl;
  }
  return 0;
}
