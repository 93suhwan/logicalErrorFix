#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long MOD1 = 1e9 + 123;
long long MOD2 = 1e9 + 321;
long long MOD3 = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, t, d, b, c, p, n, r, q, k, i, l, m, u, f, j, x, y, z;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (r / 2 < l)
      cout << r % l << "\n";
    else
      cout << r - r / 2 - 1 << "\n";
  }
  cerr << "\n\n\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
