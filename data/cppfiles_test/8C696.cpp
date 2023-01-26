#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long ans = n / 3;
  if (n % 3 == 1) {
    cout << ans + 1 << " " << ans << endl;
    return;
  } else if (n % 3 == 2) {
    cout << ans << " " << ans + 1 << endl;
    return;
  }
  cout << ans << " " << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
