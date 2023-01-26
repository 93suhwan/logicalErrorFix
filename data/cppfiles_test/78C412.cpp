#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if (l <= (r / 2) + 1) {
      ans = r % (r / 2 + 1);
    } else {
      ans = r % l;
    }
    cout << '\t' << ans << '\n';
  }
  return 0;
}
