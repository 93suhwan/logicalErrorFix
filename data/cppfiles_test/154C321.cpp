#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, z, n, i, x, min1, j, y, p, cnt, r1, r2, z3, m, z1, q, ct, k,
      p1, p2, c, max1, max2, ans, z2, sum, b, w;
  cin >> t;
  while (t--) {
    ct = 0;
    int a[3];
    set<int> s;
    for (i = 0; i < 3; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    ct = s.size();
    sort(a, a + 3);
    if (ct == 1) {
      if (a[0] % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    if (ct == 2) {
      if (a[2] == a[1]) {
        z = a[0];
      } else {
        z = a[2];
      }
      if (z % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      z = a[2] - a[0];
      if (z == a[1]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
