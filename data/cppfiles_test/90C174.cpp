#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long double PI = 3.141592653589793;
const long long maxn = 100005;
long long x, y, z, n, k;
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << "\n";
    return;
  }
  if (x > y) {
    cout << x + y << "\n";
  } else {
    if (2 * x > y) {
      cout << (x + y) / 2 << "\n";
    } else {
      long long t = y - (y % x);
      cout << (t + y) / 2 << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(15) << fixed;
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
