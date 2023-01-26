#include <bits/stdc++.h>
using namespace std;
long long int test, n;
void solve() {
  cin >> n;
  long long int ans = n / 10;
  n = n - (ans * 10);
  if (n % 9 == 0 && n != 0)
    cout << ans + 1 << "\n";
  else
    cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
