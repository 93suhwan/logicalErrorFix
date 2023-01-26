#include <bits/stdc++.h>
using namespace std;
void solve() {
  ll x, n;
  cin >> x >> n;
  ll p = 0;
  if (n == 0) {
    cout << x << "\n";
    return;
  }
  p = n + 4 - n % 4;
  p /= 4;
  ll jump[4] = {4 * (p - 1) + 1, -1, -4 * p, 0};
  ll ans;
  if (x % 2 == 0) {
    ans = x - jump[n % 4 - 1];
  } else {
    ans = x + jump[n % 4 - 1];
  }
  debug(p) cout << ans << "\n";
}
int main() {
  fastio();
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
