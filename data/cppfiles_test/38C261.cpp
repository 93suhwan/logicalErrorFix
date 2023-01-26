#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  int64_t k = n / 6, ans = (n / 6) * 15;
  n %= 6;
  if (!k)
    cout << 15 << "\n";
  else if (!n) {
    cout << ans << "\n";
    return;
  } else if (n == 1)
    cout << ans + 5 << "\n";
  else if (n == 2)
    cout << ans + 5 << "\n";
  else if (n == 3)
    cout << ans + 10 << "\n";
  else if (n == 4)
    cout << ans + 10 << "\n";
  else
    cout << ans + 15 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
