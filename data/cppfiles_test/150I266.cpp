#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ct[3] = {};
    int mx = 0;
    int mn = INT_MAX;
    while (n--) {
      int x;
      cin >> x;
      ct[x % 3]++;
      mx = max(mx, x);
      mn = min(mn, x);
    }
    int ans = mx / 3;
    if (ct[1] && ct[2]) {
      cout << (mn == 1 ? ans + 2 : ans + 1) << endl;
    } else if (ct[1] || ct[2]) {
      cout << ans + 1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
