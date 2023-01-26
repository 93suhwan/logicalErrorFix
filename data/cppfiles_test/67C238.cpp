#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long const INF = 1e10;
long long const MOD = 1e9 + 7;
long double const EPS = 1e-8;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long d = max(a, b) - min(a, b);
  if (c > 2 * d || a > 2 * d || b > 2 * d) {
    cout << -1;
    return;
  }
  if (c <= d) {
    cout << c + d;
  } else {
    cout << c - d;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  long long q = 1;
  cin >> q;
  while (q--) {
    solve();
    cout << endl;
  }
  return 0;
}
