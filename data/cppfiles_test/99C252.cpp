#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const char nl = '\n';
const long double eps = 1e-6, pi = acos(-1);
const long long N = 1e5, mod = 1e9 + 7, inf = 1e18;
void solve() {
  long long n, x;
  cin >> x >> n;
  if (x % 2 == 0) {
    if (n % 4 == 0) {
      cout << x << nl;
    } else if (n % 4 == 1) {
      cout << x - n << nl;
    } else if (n % 4 == 2) {
      cout << x + 1 << nl;
    } else {
      cout << x + 1 + n << nl;
    }
  } else {
    if (n % 4 == 0) {
      cout << x << nl;
    } else if (n % 4 == 1) {
      cout << x + n << nl;
    } else if (n % 4 == 2) {
      cout << x - 1 << nl;
    } else {
      cout << x - 1 - n << nl;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(numeric_limits<long double>::max_digits10);
  cout << setprecision(15) << fixed;
  long long tt = 1;
  cin >> tt;
  for (long long i = 1; i <= tt; ++i) {
    solve();
  }
  return 0;
}
