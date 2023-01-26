#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0, last = 31;
  while (last > 0) {
    for (long long i = 0; i < 31; i++) {
      long long x = n | ((1 << i) - 1);
      if (x > m) {
        ans = ans | (1 << i) / 2;
        n = n | (1 << i) / 2;
        last = i;
        break;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
