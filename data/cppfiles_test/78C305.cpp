#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = (r / 2 + 1);
    if (ans < l) {
      ans = r % l;
    } else {
      ans = r - ans;
    }
    cout << ans << endl;
  }
}
