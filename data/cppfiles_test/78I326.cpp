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
    int ans = r - (r / 2 + 1);
    if (ans < l) {
      ans = r % l;
    }
    cout << ans << endl;
  }
}
