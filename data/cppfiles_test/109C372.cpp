#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int q;
  cin >> q;
  while (q--) {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      char ch;
      cin >> ch;
      if (i != n) ans += (ch != '0');
      ans += ch - '0';
    }
    cout << ans << endl;
  }
}
