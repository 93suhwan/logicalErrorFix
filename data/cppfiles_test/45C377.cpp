#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  int f1 = -1, ans = 1;
  for (int x = (0); x < (n); ++x) {
    int a;
    cin >> a;
    if (ans == -1) continue;
    if (a == 1) {
      if (f1 == 1)
        ans += 5;
      else
        ans += 1;
    } else {
      if (f1 == 0) {
        ans = -1;
      }
    }
    if (a == 1)
      f1 = 1;
    else
      f1 = 0;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int x = 1; x <= t; x++) {
    solve();
  }
  return 0;
}
