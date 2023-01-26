#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, x;
  cin >> x >> n;
  if (n % 4 == 0) {
    cout << x << endl;
  } else if (n % 4 == 1) {
    if (x % 2 == 0)
      cout << x - n << endl;
    else
      cout << x + n << endl;
  } else if (n % 4 == 2) {
    if (x % 2 == 0) {
      cout << x + 1 << endl;
    } else
      cout << x - 1 << endl;
  } else {
    if (x % 2 == 0) {
      cout << x - n + n - 1 + n - 2 << endl;
    } else
      cout << x + n - n + 1 - n + 2 << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
