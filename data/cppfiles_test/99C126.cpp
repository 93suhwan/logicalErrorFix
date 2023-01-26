#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, n;
  cin >> x >> n;
  long long d = n % 4;
  if (x % 2 == 0) {
    if (d == 0)
      cout << x + 0 << "\n";
    else if (d == 1) {
      cout << x + (-n) << "\n";
    } else if (d == 2) {
      cout << x + 1 << "\n";
    } else {
      cout << x + 1 + n << "\n";
    }
  } else {
    if (d == 0)
      cout << x + 0 << "\n";
    else if (d == 1) {
      cout << x + n << "\n";
    } else if (d == 2) {
      cout << x - 1 << "\n";
    } else {
      cout << x - 1 - n << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
