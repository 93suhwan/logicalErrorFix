#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (r % 2 == 1) {
      long long ans = r / 2;
      if (ans < l) ans = r % l;
      cout << ans << "\n";
    } else {
      long long ans = r / 2;
      if (ans < l)
        ans = r % l;
      else
        ans -= 1;
      cout << ans << "\n";
    }
  }
}
