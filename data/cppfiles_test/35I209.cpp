#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
  cin >> n >> k;
  if (n > k) {
    cout << 0 << endl;
  } else {
    int t1 = log2(k);
    int ans = 0;
    for (int i = t1; i > 0; --i) {
      if ((int)log2(n) > (int)log2(k)) {
        cout << ans << endl;
        return;
      } else if ((int)log2(n) == (int)log2(k)) {
        if (n > k) {
          cout << ans << endl;
          return;
        } else {
          ans += n ^ (k + 1);
          cout << ans << endl;
          return;
        }
      }
      if ((1 << i) > k) continue;
      ans += (1 << i);
      k -= (1 << i);
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
