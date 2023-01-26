#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
  cin >> n >> k;
  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    int t1 = 0, t2 = 0;
    if (n & (1 << i)) t1 = 1;
    if (k & (1 << i)) t2 = 1;
    if (t1 && t2)
      continue;
    else if (t1) {
      cout << ans << endl;
      return;
    } else if (t2) {
      ans += (1 << i);
    } else {
      if ((k % (1 << i)) + 1 == (1 << i)) {
        cout << ans + (1 << i) << endl;
        return;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
