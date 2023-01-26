#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 10;
const long long inf = 1e17 + 10;
const long long mod = 1e9 + 7;
const long double eps = 1e-4;
const long double PI = 3.1415926535;
vector<long long> a(maxn);
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << y << '\n';
    return;
  }
  if (x > y) {
    cout << x + y << '\n';
    return;
  }
  long long a1 = 1;
  a1 = (y / x);
  if (y % x == 0) a1--;
  cout << (y + a1 * x) / 2 << '\n';
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
