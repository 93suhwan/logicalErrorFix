#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
inline void solve() {
  long long n;
  cin >> n;
  long long ans = n / 10;
  if (n % 10 == 9) ans++;
  cout << ans << endl;
  return;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
