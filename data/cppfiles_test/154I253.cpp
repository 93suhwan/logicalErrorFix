#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, z, n, i, x, min1, j, y, p, cnt, r1, r2, z3, m, z1, q, ct, k,
      p1, p2, c, max1, max2, ans, z2, sum, b, w;
  cin >> t;
  while (t--) {
    cin >> x >> y >> z;
    n = (x + y + z);
    if (n % 4 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
