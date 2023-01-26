#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll x, n;
  cin >> x >> n;
  if (x % 2 == 0) {
    if (n % 4 == 2) {
      cout << x + 1 << "\n";
      return;
    } else if (n % 4 == 1) {
      cout << x + -n << "\n";
      return;
    } else if (n % 4 == 3) {
      cout << x + n + 1 << "\n";
      return;
    } else if (n % 4 == 0) {
      cout << x + 0 << "\n";
      return;
    }
  } else {
    if (n % 4 == 2) {
      cout << x + 1 - 2 << "\n";
      return;
    } else if (n % 4 == 1) {
      cout << x + 1 + n - 1 << "\n";
      return;
    } else if (n % 4 == 3) {
      cout << x + 1 - n - 2 << "\n";
      return;
    } else if (n % 4 == 0) {
      cout << x + 1 - 1 << "\n";
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll tc;
  cin >> tc;
  while (tc--) solve();
}
