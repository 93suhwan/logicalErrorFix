#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 2; i <= n; i++) {
      if (i != 2) cout << " ";
      cout << i;
    }
  }
}
