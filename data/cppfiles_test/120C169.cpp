#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, m, p;
  cin >> p;
  for (k = 0; k < p; k++) {
    cin >> m >> n;
    int x, y;
    int z = (n - m + 1);
    n = n + 1;
    int minT = z - (n / 2) + (m / 2);
    int pow2 = 2;
    while (pow2 <= m || pow2 <= n) {
      int c1 = (m / pow2);
      int c2 = (n / pow2);
      x = (c1 / 2) * pow2;
      y = (c2 / 2) * pow2;
      x += (c1 % 2 == 0) ? 0 : (m % pow2);
      y += (c2 % 2 == 0) ? 0 : (n % pow2);
      minT = min(minT, z - y + x);
      pow2 = pow2 * 2;
    }
    cout << minT << endl;
  }
}
