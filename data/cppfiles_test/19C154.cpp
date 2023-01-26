#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int smask = mask; smask; smask = (smask - 1) & mask) {
      int sum = 0;
      for (int i = 0; i < n; i++)
        if (mask & (1 << i)) {
          if (smask & (1 << i))
            sum += v[i];
          else
            sum -= v[i];
        }
      if (!sum) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
