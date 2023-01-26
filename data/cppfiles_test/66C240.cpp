#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int k;
    cin >> k;
    int ans = 0;
    while (k-- > 0) {
      ans += 1;
      if (ans % 3 == 0 or ans % 10 == 3) ans += 1;
      if (ans % 3 == 0 or ans % 10 == 3) ans += 1;
    }
    cout << ans << endl;
  }
}
