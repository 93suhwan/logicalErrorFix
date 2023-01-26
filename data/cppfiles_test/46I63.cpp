#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 9, mod = 1e9 + 7;
int n, a[100005];
void solve() {
  cin >> n;
  int mx = -inf, flag = 0, mn = -inf;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0 and !flag) {
      if (a[i] != a[i - 1]) flag = 1;
    }
    mx = max(mx, a[i]);
  }
  if (n == 1 or !flag) {
    cout << 0 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == mx) {
      mn = *max_element(a + i + 1, a + n);
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == mn) {
      cout << n - i << '\n';
      return;
    }
  }
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
