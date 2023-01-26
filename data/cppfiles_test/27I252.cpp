#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const bool debugFlag = true;
const lint linf = 1e18 + 7;
const lint inf = 1e9 + 7;
const int MOD = 1000000007;
void solve() {
  lint n, m, k;
  cin >> n >> m >> k;
  if (m < n - 1 || m > n * (n - 1) / 2) {
    cout << "NO"
         << "\n";
    return;
  }
  if (n == 1) {
    cout << "YES"
         << "\n";
    return;
  }
  if (k == 3) {
    if (m == n * (n - 1) / 2) {
      cout << "YES"
           << "\n";
    } else
      cout << "NO"
           << "\n";
    return;
  }
  if (k <= 2) {
    if (n == 1)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
    return;
  }
  cout << "YES"
       << "\n";
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
