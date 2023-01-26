#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      mn = min(mn, ar[i]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      ans = min(ans, ar[i] & mn);
    }
    cout << ans << endl;
  }
  return 0;
}
