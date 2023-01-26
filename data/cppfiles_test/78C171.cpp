#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if (l <= r / 2) {
      if (r % 2 == 0)
        ans = r / 2 - 1;
      else
        ans = r / 2;
    } else
      ans = r % l;
    cout << ans << "\n";
  }
}
