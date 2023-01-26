#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    long long ans = r % ((r / 2) + 1);
    if (ans < l) {
      cout << r % l << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
